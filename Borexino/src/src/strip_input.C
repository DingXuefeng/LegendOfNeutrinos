#include "TFile.h"
#include <vector>
#include <string>
#include "TH1.h"

void strip_input(std::string input_fc,
                 std::string output_fc,
                 std::vector<std::string> hists,
                 bool keepQ = true,
                 bool keepNpmt = false,
                 bool keepNhit = false,
                 bool keepMV = false) {
  TFile *input_f = TFile::Open(input_fc.c_str());
  TFile *output_f = TFile::Open(output_fc.c_str(), "RECREATE");

  auto Nhit = {"pp/final_nhits_pp",
               "pp/final_nhits_pp_0",
               "pp/final_nhits_pp_1",
  };
  auto Npmt = {
      "pp/final_npmts_dt1_pp",
      "pp/final_npmts_dt1_pp_0",
      "pp/final_npmts_dt1_pp_1",
      "pp/h_n_used_pmts",
      "pp/h_n_used_pmts_weighted",
      "pp/h_n_used_pmts0",
      "pp/h_n_used_pmts1",
      "pp/h_n_used_pmts_weighted0",
      "pp/h_n_used_pmts_weighted1",
      "pp/npmts_win1_norm",
      "MC_pdfs/ext_tl208_npmts_dt1",
      "MC_pdfs/ext_bi214_npmts_dt1",
      "MC_pdfs/ext_k40_npmts_dt1",
  };
  auto Npe = {
      "pp/geometrical_correction/final_charge_pp_geo_0", "pp/geometrical_correction/final_charge_pp_geo_1",
      "pp/geometrical_correction/final_charge_pp_geo", "pp/geometrical_correction/h_n_used_charge_weighted_geo",
      "pp/geometrical_correction/h_n_used_charge_pp_geo",
      "MC_pdfs/ext_tl208_charge",
      "MC_pdfs/ext_bi214_charge",
      "MC_pdfs/ext_k40_charge",
  };
  auto MV = {
      "pp/Rdist_pp/multivariate_rdist_data_npmts_dt1_pp",
      "pp/User_pp/multivariate_lkl_data_npmts_dt1_pp",
      "multivariate/multivariate_lkl_1_npmts_dt1",
      "multivariate/multivariate_lkl_0_npmts_dt1",
      "multivariate/multivariate_rdist_1_npmts_dt1",
      "multivariate/multivariate_rdist_0_npmts_dt1",
  };
  std::vector<std::string> histos = {
      "chain_counts_cum",
  };
  histos.insert(histos.end(), hists.begin(), hists.end());
  if (keepQ) histos.insert(histos.end(), Npe.begin(), Npe.end());
  if (keepNpmt) histos.insert(histos.end(), Npmt.begin(), Npmt.end());
  if (keepNhit) histos.insert(histos.end(), Nhit.begin(), Nhit.end());
  if (keepMV) histos.insert(histos.end(), MV.begin(), MV.end());
  if (input_f)
    for (auto h : histos) {
      TH1 *target = (TH1 *) input_f->Get(h.c_str());
      if (target) {
        output_f->cd();
        int p;
        while (h.find("/") != std::string::npos) {
          p = h.find("/");
          auto folder = h.substr(0, p);
          h = h.substr(p + 1);
          if (!gDirectory->Get(folder.c_str())) gDirectory->mkdir(folder.c_str());
          gDirectory->cd(folder.c_str());
        }
        target->Write();
      }
    }
  output_f->Close();
}
