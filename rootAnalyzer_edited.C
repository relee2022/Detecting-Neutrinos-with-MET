//load some stuff that we need
#include "TFile.h"
#include "TTree.h"
#include <TDirectory.h>
#include "TH1D.h"
#include "TMath.h"
#include "TVector3.h"
#include "TCanvas.h"
#include "TLegend.h"
#include <vector>
#include <iostream>

//the code execution starts here
void rootAnalyzer(){
  bool TestRun=1;

  //define some variables we need for later
  std::vector<float> * genPt = 0;
  std::vector<float> * genEta = 0;
  std::vector<float> * genPhi = 0;
  std::vector<int> * genPdg = 0;
  std::vector<int> * genChg = 0;

  std::vector<float> * recoPt = 0;
  std::vector<float> * recoEta = 0;
  std::vector<float> * recoPhi = 0;
  std::vector<int> * recoId = 0;

  //open the input file
  /*TFile *file = new TFile("rootAnalyzer.C", "CREATE");
    TDirectory *newDir = file->mkdir("Reco/Gen");
    newDir->cd();*/

  //TFile * f = TFile::Open("neutrinoStudy_TEST_MBpp.root","read");
  TFile * f = TFile::Open("C:/Users/user/Desktop/pp_withNeutrino_HiForestMiniAOD.root","read");

  //setup the info for gen tree
  TTree * genTree = (TTree*) f->Get("HiGenParticleAna/hi");
  genTree->SetBranchAddress("pt",&genPt);
  genTree->SetBranchAddress("eta",&genEta);
  genTree->SetBranchAddress("phi",&genPhi);
  genTree->SetBranchAddress("pdg",&genPdg);
  genTree->SetBranchAddress("chg",&genChg);

  //setup the info for reco tree
  TTree * recoTree = (TTree*) f->Get("particleFlowAnalyser/pftree");
  recoTree->SetBranchAddress("pfPt",&recoPt);
  recoTree->SetBranchAddress("pfEta",&recoEta);
  recoTree->SetBranchAddress("pfPhi",&recoPhi);
  recoTree->SetBranchAddress("pfId",&recoId);

  //Raven: define analysis variables under here until next comment!
   TH1* h1 = new TH1F("h1", "Pt;X-axis;Occurences", 100, -2.0, 6.0);
   TH1* h2 = new TH1F("h2", "Eta;eta;Occurences", 100, -6.0, 6.0);
   TH1* h3 = new TH1F("h3", "Phi;phi;Occurences", 100, -6.0, 6.0);

   TH1* h4 = new TH1F("h4", "Reco Pt;pt;Occurences;", 100, -2.0, 6.0);
   TH1* h5 = new TH1F("h5", "Reco Eta;eta;Occurences", 100, -6.0, 6.0);
   TH1* h6 = new TH1F("h6", "Reco Phi;phi;Occurences", 100, -6.0, 6.0);

  
  float myExampleVariables = 0;


    TH1* h7 = new TH1F("h7", "GenPt_x;Px;", 100, -4.0, 4.0);
    TH1* h8 = new TH1F("h8", "GenPt_y;Py;", 100, -4.0, 4.0);
    TH1* h9 = new TH1F("h9", "RecoPt_x;Px", 100, -4.0, 4.0);
    TH1* h10 = new TH1F("h10", "RecoPt_y;Py", 100, -4.0, 4.0);

    
    TH1* h11 = new TH1F("h11", "GenPn;Pn_x;", 100, -20.0, 20.0);
    TH1* h12 = new TH1F("h12", "GenPn_;Pn_y;", 100, -20.0, 20.0);
    TH1* h13 = new TH1F("h13", "RecoPn2;Pn_x", 100, -20.0, 20.0);
    TH1* h14 = new TH1F("h14", "RecoPn2_;Pn_y", 100, -20.0, 20.0);

    TH1* h15 = new TH1F("h15", "GenPt_new;Pt;", 100, -20.0, 20.0);
    TH1* h16 = new TH1F("h16", "GenPhi_new;Phi;", 100, TMath::Pi(), TMath::Pi());
    TH1* h17 = new TH1F("h17", "RecoPt_new;Pt", 100, -20.0, 20.0);
    TH1* h18 = new TH1F("h18", "RecoPhi_new;Phi", 100, TMath::Pi(), TMath::Pi());

    TH1* h_isGenPhiZero = new TH1F("h_isGenPhiZero", "isGenPhiZero;Phi", 100, TMath::Pi(), TMath::Pi());
    TH1* h_isGenPhiZeroY = new TH1F("h_isGenPhiZeroY", "isGenPhiZeroY;Phi", 100, TMath::Pi(), TMath::Pi());


  //stop here!

  //loop through each event with index i
  int numEntries = (TestRun) ? 100 : genTree->GetEntries();
  for(int i = 0; i<numEntries; i++){
    std::cout << "\nStarting event number: " << i << std::endl;

    //load the gen particles
    genTree->GetEntry(i);
    std::cout << "Gen Loop:" << std::endl;

      float Pn=0,Pn2=0,Pn3=0,Pn4=0, genPt_new=0,recoPt_new=0,genPhi_new=0,recoPhi_new=0,CMS_effPhi=0,CMS_effPt=0;

    //loop through the gen particles (there are j of them)
    for(unsigned int j = 0; j<genPt->size(); j++){
      //std::cout << genPt->at(j) << " " << genEta->at(j) << " " << genPhi->at(j) << " " << genPdg->at(j) << " " << genChg->at(j) << std::endl;

      //******************** Raven: Analysis code goes under here! ***************************//
      h1->Fill(genPt->at(j));
      h2->Fill(genEta->at(j));
      h3->Fill(genPhi->at(j));


    float Py= genPt->at(j)*(TMath::Sin(genPhi->at(j)));
    float Px=genPt->at(j)*(TMath::Cos(genPhi->at(j)));

      h7->Fill(Px);
      h8->Fill(Py);

     Pn += -(Px);
     Pn2 += -(Py);
    
    genPt_new=TMath::Sqrt(TMath::Power(Pn,2)+TMath::Power(Pn2,2));

    if(Pn>0)
    {
      genPhi_new=TMath::ATan(Pn2/Pn);
    }

      else if (Pn<0)
      {
        genPhi_new=TMath::ATan2(Pn2,Pn);
      }
      else 
      {
      std::cout<<"Invalid"<<std::endl;
      }
  
      //stop here!
    }
     h11->Fill(Pn);
     h12->Fill(Pn2); 

     
     if (genPhi_new==0)
      {
    
      
      h_isGenPhiZero->Fill(Pn);
      h_isGenPhiZeroY->Fill(Pn2);

      }
      
    
     h15->Fill(genPt_new);
     h16->Fill(genPhi_new);

    //load the reco particles
    recoTree->GetEntry(i);
    std::cout << "Reco Loop:" << std::endl;
   // loop through the reco particles (there are j of them)
    for(unsigned int j = 0; j<recoPt->size(); j++){
       //std::cout << recoPt->at(j) << " " << recoEta->at(j) << " " << recoPhi->at(j) << " " << recoId->at(j) << std::endl;

        //******************** Raven: Analysis code goes under here! ***************************//
    

      h4->Fill(recoPt->at(j));
      h5->Fill(recoEta->at(j));                   
      h6->Fill(recoPhi->at(j));


      float Py2= recoPt->at(j)*(TMath::Sin(recoPhi->at(j)));       //Get Px,Py
      float Px2=recoPt->at(j)*(TMath::Cos(recoPhi->at(j)));  

      h9->Fill(Px2);                                      //Fill Reco Px,Py
      h10->Fill(Py2);
      
       Pn3 += -(Px2);
       Pn4 += -(Py2);
       
       recoPt_new=TMath::Sqrt(TMath::Power(Pn3,2)+TMath::Power(Pn4,2));

      if(Pn3>0)
      {
        recoPhi_new=TMath::ATan(Pn4/Pn3);
      }

       else if (Pn3<0)
        {
         recoPhi_new=TMath::ATan2(Pn4,Pn3);
        }
         else 
         {
        std::cout<<"Invalid"<<std::endl;
         }


        //stop here!
    }
            //Fill Added Vectors for Gen/Reco
     h13->Fill(Pn3);
     h14->Fill(Pn4);
  
     h17->Fill(recoPt_new);
     h18->Fill(recoPhi_new);

     CMS_effPt=recoPt_new-genPt_new;
     CMS_effPhi=recoPhi_new-genPhi_new;
  }

  h1-> SetLineColor(kRed);             //Set Color of Gen
  h2-> SetLineColor(kRed);
  h3-> SetLineColor(kRed);

  float n = h4->GetEntries();         //Normalize Graphs to 1
  float n2 = h5->GetEntries();
  float n3 = h6->GetEntries();


  float n4 = h1->GetEntries();
  float n5 = h2->GetEntries();
  float n6 = h3->GetEntries();

  h4->Scale(1.0 / n);
  h5->Scale(1.0 / n2);
  h6->Scale(1.0 / n3);
   h1->Scale(1.0 / n4);
  h2->Scale(1.0 / n5);
  h3->Scale(1.0 / n6);


      TCanvas *c = new TCanvas();
      h1->Draw(); 
      h4->Draw("SAME");
      TLegend *legend = new TLegend(0.1, 0.7, 0.3, 0.9); 
      legend->AddEntry(h1, "genPt", "l"); // "l" specifies line for histogram
      legend->AddEntry(h4, "recoPt", "l");
      legend->SetTextSize(.03); 
      legend->Draw();

      TCanvas *c1 = new TCanvas();
      h2->Draw();
      h5->Draw("SAME");
      TLegend *legend = new TLegend(0.1, 0.7, 0.3, 0.9); 
      legend->AddEntry(h2, "genPt", "l"); // "l" specifies line for histogram
      legend->AddEntry(h5, "recoPt", "l");
      legend->SetTextSize(0.03); 
      legend->Draw();
  
      TCanvas *c2 = new TCanvas();
      h3->Draw();
      h6->Draw("SAME");
      TLegend *legend = new TLegend(0.1, 0.7, 0.3, 0.9); 
      legend->AddEntry(h3, "genPt", "l"); // "l" specifies line for histogram
      legend->AddEntry(h6, "recoPt", "l");
      legend->SetTextSize(0.03); 
      legend->Draw();

     TCanvas *c3 = new TCanvas();
     h7->Draw();
     TCanvas *c4 = new TCanvas();
     h8->Draw();
     TCanvas *c5 = new TCanvas();
     h9->Draw();
     TCanvas *c6 = new TCanvas();
     h10->Draw();

     TCanvas *c7 = new TCanvas();
     h11->Draw();
     TCanvas *c8 = new TCanvas();
     h12->Draw();
     TCanvas *c9 = new TCanvas();
     h13->Draw();
     TCanvas *c10 = new TCanvas();
     h14->Draw();

    TCanvas *c11 = new TCanvas();
     h15->Draw();
     TCanvas *c12 = new TCanvas();
     h16->Draw();
     TCanvas *c13= new TCanvas();
     h17->Draw();
     TCanvas *c14 = new TCanvas();
     h18->Draw();

    TCanvas *c_isGenZero = new TCanvas();
     h_isGenPhiZero->Draw();
    TCanvas *c_isGenZeroY = new TCanvas();
     h_isGenPhiZeroY->Draw();
/*c->SaveAs("C:/Users/user/Desktop/RecoGen_pt.png");    
c1->SaveAs("C:/Users/user/Desktop/RecoGen_eta.png");
c2->SaveAs("C:/Users/user/Desktop/RecoGen_phi.png");
c3->SaveAs("C:/Users/user/Desktop/Gen_px.png");
c4->SaveAs("C:/Users/user/Desktop/Gen_py.png");
c5->SaveAs("C:/Users/user/Desktop/Reco_px.png");
c6->SaveAs("C:/Users/user/Desktop/Reco_py.png");
c7->SaveAs("C:/Users/user/Desktop/Gen_pnx.png");
c8->SaveAs("C:/Users/user/Desktop/Gen_pny.png");
c9->SaveAs("C:/Users/user/Desktop/Reco_pnx.png");
c10->SaveAs("C:/Users/user/Desktop/Reco_pny.png"); */

}
