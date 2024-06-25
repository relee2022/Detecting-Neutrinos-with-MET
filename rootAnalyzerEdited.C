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
  bool TestRun= 0;

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

    TFile * f2 = TFile::Open("C:/Users/user/Desktop/pp_noNeutrino_HiForestMiniAOD.root","read");

 //setup the info for gen tree
  TTree * genTree2 = (TTree*) f2->Get("HiGenParticleAna/hi");
  genTree2->SetBranchAddress("pt",&genPt);
  genTree2->SetBranchAddress("eta",&genEta);
  genTree2->SetBranchAddress("phi",&genPhi);
  genTree2->SetBranchAddress("pdg",&genPdg);
  genTree2->SetBranchAddress("chg",&genChg);

  //setup the info for reco tree
  TTree * recoTree2 = (TTree*) f2->Get("particleFlowAnalyser/pftree");
  recoTree2->SetBranchAddress("pfPt",&recoPt);
  recoTree2->SetBranchAddress("pfEta",&recoEta);
  recoTree2->SetBranchAddress("pfPhi",&recoPhi);
  recoTree2->SetBranchAddress("pfId",&recoId);

  //Raven: define analysis variables under here until next comment!
   TH1* h1 = new TH1F("h1", "GenPt;X-axis;Occurences", 100, -2.0, 6.0);
   TH1* h2 = new TH1F("h2", "GenEta;eta;Occurences", 100, -6.0, 6.0);
   TH1* h3 = new TH1F("h3", "GenPhi;phi;Occurences", 100, -6.0, 6.0);
   TH1* h1_2 = new TH1F("h1", "GenPt;X-axis;Occurences", 100, -2.0, 6.0);
   TH1* h2_2 = new TH1F("h2", "GenEta;eta;Occurences", 100, -6.0, 6.0);
   TH1* h3_2 = new TH1F("h3", "GenPhi;phi;Occurences", 100, -6.0, 6.0);

   TH1* h4 = new TH1F("h4", "Reco Pt;pt;Occurences;", 100, -2.0, 6.0);
   TH1* h5 = new TH1F("h5", "Reco Eta;eta;Occurences", 100, -6.0, 6.0);
   TH1* h6 = new TH1F("h6", "Reco Phi;phi;Occurences", 100, -6.0, 6.0);
   TH1* h4_2 = new TH1F("h4", "Reco Pt;pt;Occurences;", 100, -2.0, 6.0);
   TH1* h5_2 = new TH1F("h5", "Reco Eta;eta;Occurences", 100, -6.0, 6.0);
   TH1* h6_2 = new TH1F("h6", "Reco Phi;phi;Occurences", 100, -6.0, 6.0);
  
  float myExampleVariables = 0;


    TH1* h7 = new TH1F("h7", "GenPt_x;Px;", 100, -4.0, 4.0);
    TH1* h8 = new TH1F("h8", "GenPt_y;Py;", 100, -4.0, 4.0);
    TH1* h7_2 = new TH1F("h7_2", "GenPt_x;Px;", 100, -4.0, 4.0);
    TH1* h8_2 = new TH1F("h8_2", "GenPt_y;Py;", 100, -4.0, 4.0);
    TH1* h9 = new TH1F("h9", "RecoPt_x;Px", 100, -4.0, 4.0);
    TH1* h10 = new TH1F("h10", "RecoPt_y;Py", 100, -4.0, 4.0);
    TH1* h9_2 = new TH1F("h9_2", "RecoPt_x;Px", 100, -4.0, 4.0);
    TH1* h10_2 = new TH1F("h10_2", "RecoPt_y;Py", 100, -4.0, 4.0);

    
    TH1* h11 = new TH1F("h11", "GenPn;Pn_x;", 100, -40.0, 40.0);
    TH1* h12 = new TH1F("h12", "GenPn_;Pn_y;", 100, -40.0, 40.0);
    TH1* h13 = new TH1F("h13", "RecoPn2;Pn_x", 100, -40.0, 40.0);
    TH1* h14 = new TH1F("h14", "RecoPn2_;Pn_y", 100, -40.0, 40.0);
    TH1* h11_2 = new TH1F("h11_2", "GenPn;Pn_x;", 100, -40.0, 40.0);
    TH1* h12_2 = new TH1F("h12_2", "GenPn_;Pn_y;", 100, -40.0, 40.0);
    TH1* h13_2 = new TH1F("h13_2", "RecoPn2;Pn_x", 100, -40.0, 40.0);
    TH1* h14_2 = new TH1F("h14_2", "RecoPn2_;Pn_y", 100, -40.0, 40.0);

    TH1* h15 = new TH1F("h15", "GenPt_new;Pt;", 100, 0, 100.0);
   // TH1* h_newPtless = new TH1F("h_newPtless", "genPt_new-less;Pt;", 100, 0, 100.0);
    TH1* h15_2 = new TH1F("h15_2", "GenPt_new-no;Pt;", 100, 0, 100.0);


    TH1* h16 = new TH1F("h16", "GenPhi_new;Phi;", 100, TMath::Pi(), TMath::Pi());
    TH1* h16_2 = new TH1F("h16_2", "GenPhi_new;Phi;", 100, TMath::Pi(), TMath::Pi());
    TH1* h17 = new TH1F("h17", "RecoPt_new;Pt", 100, 0, 70.0);
    TH1* h18 = new TH1F("h18", "RecoPhi_new;Phi", 100, TMath::Pi(), TMath::Pi());
    TH1* h17_2 = new TH1F("h17_2", "RecoPt_new-with;Pt", 100, 0, 70.0);
    TH1* h18_2 = new TH1F("h18_2", "RecoPhi_new-no;Phi", 100, TMath::Pi(), TMath::Pi());
    
    TH1* h_isGenPhiZero = new TH1F("h_isGenPhiZero", "isGenPhiZero;Phi", 100, TMath::Pi(), TMath::Pi());
    TH1* h_isGenPhiZeroY = new TH1F("h_isGenPhiZeroY", "isGenPhiZeroY;Phi", 100, TMath::Pi(), TMath::Pi());

    
    TH1* h_CMSPt = new TH1F("h_CMSPt", "Reco-GenPt;Pt", 100, -40,80);
    TH1* h_CMSPhi = new TH1F("h_CMSPhi", "Reco-GenPhi;Phi", 100, -10,10);
    TH1* h_CMSPt2 = new TH1F("h_CMSPt2", "Reco-GenPt_no;Eta", 100, -20,20);
    TH1* h_CMSPhi2 = new TH1F("h_CMSPhi2", "Reco-GenPhi-no;Phi", 100, -10,10);

   TH1* h_lessRecoPt = new TH1F("h_lessRecoPt", "RecoPt;X-axis;Occurences", 100, 0.0, 60.0);
   TH1* h_moreRecoPt = new TH1F("h_moreRecoPt", "RecoPt;X-axis;Occurences", 100, 0.0, 60.0);
   TH1* h_nuPhi = new TH1F("h_nuPhi", "NuPhi;phi;Occurences", 100, -20.0, 60.0);
   TH1* h_nuEta= new TH1F("h_nuEta", "NuEta;eta;Occurences", 100, -20.0, 40.0);
   TH1* h_nuPt = new TH1F("h_nuPt", "NuPt;X-axis;Occurences", 100, 0.0, 60.0);
   TH1* h_nuPhiless = new TH1F("h_nuPhiless", "NuPhi;phi;Occurences", 100, -20.0, 60.0);
   //TH1* h_nuEtaL new TH1F("h_nuEtaL", "NuEta;eta;Occurences", 100, -20.0, 40.0);
   TH1* h_nuPtless = new TH1F("h_nuPtless", "NuPt;X-axis;Occurences", 100, 0.0, 60.0);

   TH2* hPtEta = new TH2F("hPtEta", "Pt & Eta;Pt;Eta", 100, 0.0, 60.0, 100, -4,4);
   TH2* hPtEta_less = new TH2F("hPtEta_less", "Pt & Eta <= 20;Pt;Eta", 100, 0.0, 60.0, 100, -4,4);
    TH2* hRecoGenPt = new TH2F("hRecoGenPt", "Reco V. Gen Pt;Reco;Gen", 100, 0.0, 60.0, 100, 0,60);



  //loop through each event with index i
  int numEntries = (TestRun) ? 100 : genTree->GetEntries();
  for(int i = 0; i<numEntries; i++){
    std::cout << "\nStarting event number: " << i << std::endl;

    //load the gen particles
    genTree->GetEntry(i);
    std::cout << "Gen Loop:" << std::endl;

      float Pn=0,Pn2=0,Pn3=0,Pn4=0, genPt_new=0,recoPt_new=0,genPhi_new=0,recoPhi_new=0,CMS_effPhi=0,CMS_effPt=0, nuPt=-20;

    //loop through the gen particles (there are j of them)
    for(unsigned int j = 0; j<genPt->size(); j++){
      //std::cout << genPt->at(j) << " " << genEta->at(j) << " " << genPhi->at(j) << " " << genPdg->at(j) << " " << genChg->at(j) << std::endl;

      //******************** Raven: Analysis code goes under here! ***************************//

      h1->Fill(genPt->at(j));
      h2->Fill(genEta->at(j));
      h3->Fill(genPhi->at(j));

        if (genPdg->at(j) == 12 || genPdg->at(j) == 14 || genPdg->at(j) == 16 || genPdg->at(j) == -12 || genPdg->at(j) == -14 || genPdg->at(j) == -16) {
          nuPt=genPt->at(j);
          nuPhi=genPhi->at(j);
          nuEta=genEta->at(j);

        } 


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

     if (genPdg->at(j) == 12 || genPdg->at(j) == 14 || genPdg->at(j) == 16 || genPdg->at(j) == -12 || genPdg->at(j) == -14 || genPdg->at(j) == -16) 
     {
      continue;
     }

     h11->Fill(Pn);
     h12->Fill(Pn2); 

     
    /* if (genPhi_new==0)
      {
    
      
      h_isGenPhiZero->Fill(Pn);
      h_isGenPhiZeroY->Fill(Pn2);

      } */
      
 
     h15->Fill(genPt_new);                  // If Found neutrino Pt is less than 20 or greater than 20 make new histogram
     h16->Fill(genPhi_new);


    }

    //load the reco particles
    recoTree->GetEntry(i);
    std::cout << "Reco Loop:" << std::endl;
   // loop through the reco particles (there are j of them)
    for(unsigned int j = 0; j<recoPt->size(); j++){
       //std::cout << recoPt->at(j) << " " << recoEta->at(j) << " " << recoPhi->at(j) << " " << recoId->at(j) << std::endl;
    

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


      if(Pn3>0)                                          //Allows us to graph New phi in all regions
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


        if (recoEta>-2.4 || recoEta<2.4)
        {
            continue;
        }

    }

        h13->Fill(Pn3);                        //Fill Added Vectors for Gen/Reco
        h14->Fill(Pn4);
            
        
     h17->Fill(recoPt_new);
     h18->Fill(recoPhi_new);

     hRecoGenPt->Fill(recoPt_new,genPt_new);

     CMS_effPt=recoPt_new-genPt_new;
     CMS_effPhi=recoPhi_new-genPhi_new;

    h_CMSPt->Fill(CMS_effPt);
     h_CMSPhi->Fill(CMS_effPhi);


    if (CMS_effPt>15)
     {
      h_nuPt->Fill(nuPt);
      h_nuPhi->Fill(nuPhi);
      h_nuEta->Fill(nuEta);
      h_moreRecoPt->Fill(recoPt_new);
      hPtEta->Fill(nuPt,nuEta);

     /* hreco1->Fill(recoPt->at(j));
      hreco2->Fill(recoEta->at(j));                   
      hreco3->Fill(recoPhi->at(j));*/
     }
     
  if (CMS_effPt<=15)
     {
            h_nuPtless->Fill(nuPt);
      h_nuPhiless->Fill(nuPhi);
    //  h_nuEtaL->Fill(nuEta);
        h_lessRecoPt->Fill(recoPt_new);
              hPtEta_less->Fill(nuPt,nuEta);

     }
     
  }



  //SECOND FILE LOOP

  int numEntries2 = (TestRun) ? 100 : genTree2->GetEntries();
  for(int i = 0; i<numEntries2; i++){
    std::cout << "\nStarting event number: " << i << "No neutrinos"<< std::endl;

    //load the gen particles
    genTree2->GetEntry(i);
    std::cout << "Gen Loop No Neutrinos:" << std::endl;

      float Pn=0,Pn2=0,Pn3=0,Pn4=0, genPt_new=0,recoPt_new=0,genPhi_new=0,recoPhi_new=0,CMS_effPhi=0,CMS_effPt=0;

    //loop through the gen particles (there are j of them)
    for(unsigned int j = 0; j<genPt->size(); j++){
      //std::cout << genPt->at(j) << " " << genEta->at(j) << " " << genPhi->at(j) << " " << genPdg->at(j) << " " << genChg->at(j) << std::endl;

      h1_2->Fill(genPt->at(j));
      h2_2->Fill(genEta->at(j));
      h3_2->Fill(genPhi->at(j));


    float Py= genPt->at(j)*(TMath::Sin(genPhi->at(j)));
    float Px=genPt->at(j)*(TMath::Cos(genPhi->at(j)));

      h7_2->Fill(Px);
      h8_2->Fill(Py);

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

     if (genPdg->at(j) == 12 || genPdg->at(j) == 14 || genPdg->at(j) == 16 || genPdg->at(j) == -12 || genPdg->at(j) == -14 || genPdg->at(j) == -16) 
     {
      continue;
     }
     

     h11_2->Fill(Pn);
     h12_2->Fill(Pn2); 

     
     if (genPhi_new==0)
      {
    
      
      h_isGenPhiZero->Fill(Pn);
      h_isGenPhiZeroY->Fill(Pn2);

      }
      
     h15_2->Fill(genPt_new);
     h16_2->Fill(genPhi_new);

    }

    //load the reco particles
    recoTree2->GetEntry(i);
    std::cout << "Reco Loop No Neutrinos:" << std::endl;
   // loop through the reco particles (there are j of them)
    for(unsigned int j = 0; j<recoPt->size(); j++){
       //std::cout << recoPt->at(j) << " " << recoEta->at(j) << " " << recoPhi->at(j) << " " << recoId->at(j) << std::endl;
    

      h4_2->Fill(recoPt->at(j));
      h5_2->Fill(recoEta->at(j));                   
      h6_2->Fill(recoPhi->at(j));


      float Py2= recoPt->at(j)*(TMath::Sin(recoPhi->at(j)));       //Get Px,Py
      float Px2=recoPt->at(j)*(TMath::Cos(recoPhi->at(j)));  

      h9_2->Fill(Px2);                                      //Fill Reco Px,Py
      h10_2->Fill(Py2)
      
       Pn3 += -(Px2);
       Pn4 += -(Py2);                                          //Add Px's/Py's to get new vector
                                                               
       
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


        if (recoEta>-2.4 || recoEta<2.4 )
        {
            continue;
        }

    }

      //Fill Added Vectors Reco
     h13_2->Fill(Pn3);
     h14_2->Fill(Pn4);

       //Fill new values of reco Pt/Phi
     h17_2->Fill(recoPt_new);
     h18_2->Fill(recoPhi_new);

     CMS_effPt=recoPt_new-genPt_new;
     CMS_effPhi=recoPhi_new-genPhi_new;


    h_CMSPt2->Fill(CMS_effPt);
     h_CMSPhi2->Fill(CMS_effPhi);
  }

  h1-> SetLineColor(kRed);             //Set Color of Gen
  h2-> SetLineColor(kRed);
  h3-> SetLineColor(kRed);
  h1_2-> SetLineColor(kRed);             //Set Color of Gen
  h2_2-> SetLineColor(kRed);             //Set Color of Gen
  h3_2-> SetLineColor(kRed);             //Set Color of Gen
  h11_2-> SetLineColor(kRed);             //Set Color of Gen
  h12_2-> SetLineColor(kRed);
  h13_2-> SetLineColor(kRed);
  h14_2-> SetLineColor(kRed);

 

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

      TCanvas *c_2 = new TCanvas();
          h1_2->Draw();
          h4_2->Draw("SAME");
      TLegend *legend1 = new TLegend(0.1, 0.7, 0.3, 0.9); 
      legend1->AddEntry(h1_2, "genPt_no", "l"); // "l" specifies line for histogram
      legend1->AddEntry(h4_2, "recoPt_no", "l");
      legend1->SetTextSize(.03); 
      legend1->Draw();


      TCanvas *c1 = new TCanvas();
      h2->Draw();
      h5->Draw("SAME");
      TLegend *legend2 = new TLegend(0.1, 0.7, 0.3, 0.9); 
      legend2->AddEntry(h2, "genPt", "l"); // "l" specifies line for histogram
      legend2->AddEntry(h5, "recoPt", "l");
      legend2->SetTextSize(0.03); 
      legend2->Draw();

      TCanvas *c1_2 = new TCanvas();
       h2_2->Draw();
       h5_2->Draw("SAME");
      TLegend *legend3 = new TLegend(0.1, 0.7, 0.3, 0.9); 
      legend3->AddEntry(h2_2, "genPt_no", "l"); // "l" specifies line for histogram
      legend3->AddEntry(h5_2, "recoPt_no", "l");
      legend3->SetTextSize(0.03); 
      legend3->Draw();
  
      TCanvas *c2 = new TCanvas();
      h3->Draw();
      h6->Draw("SAME");
      TLegend *legend4 = new TLegend(0.1, 0.7, 0.3, 0.9); 
      legend4->AddEntry(h3, "genPt", "l"); // "l" specifies line for histogram
      legend4->AddEntry(h6, "recoPt", "l");
      legend4->SetTextSize(0.03); 
      legend4->Draw();

      TCanvas *c2_2 = new TCanvas();
      h3_2->Draw();
      h6_2->Draw("SAME");
      TLegend *legend5 = new TLegend(0.1, 0.7, 0.3, 0.9); 
        legend5->AddEntry(h3_2, "recoPt_no", "l");
        legend5->AddEntry(h6_2, "recoPt_no", "l");
      legend5->SetTextSize(0.03); 
      legend5->Draw();

  h7_2-> SetLineColor(kRed);             //Set Color of No neutrino
  h8_2-> SetLineColor(kRed);
  h9_2-> SetLineColor(kRed);
  h10_2-> SetLineColor(kRed);

      TCanvas *cpx = new TCanvas();
      h7->Draw();
      h7_2->Draw("SAME");
      TLegend *legend6 = new TLegend(0.1, 0.7, 0.3, 0.9); 
      legend6->AddEntry(h7, "with neutrino", "l"); // "l" specifies line for histogram
      legend6->AddEntry(h7_2, "no neutrino", "l");
      legend6->SetTextSize(0.03); 
      legend6->Draw();

      TCanvas *cpy = new TCanvas();
      h8->Draw();
      h8_2->Draw("SAME");
      TLegend *legend7 = new TLegend(0.1, 0.7, 0.3, 0.9); 
      legend7->AddEntry(h8, "with", "l"); // "l" specifies line for histogram
      legend7->AddEntry(h8_2, "no neutrino", "l");
      legend7->SetTextSize(0.03); 
      legend7->Draw();

      TCanvas *cpx_reco = new TCanvas();
      h9->Draw();
      h9_2->Draw("SAME");
      TLegend *legend8 = new TLegend(0.1, 0.7, 0.3, 0.9); 
      legend8->AddEntry(h9, "with", "l"); // "l" specifies line for histogram
      legend8->AddEntry(h9_2, "no neutrino", "l");
      legend8->SetTextSize(0.03); 
      legend8->Draw();
 
      TCanvas *cpy_reco = new TCanvas();
      h10->Draw();
      h10_2->Draw("SAME");
      TLegend *legend9 = new TLegend(0.1, 0.7, 0.3, 0.9); 
      legend9->AddEntry(h10, "with", "l"); // "l" specifies line for histogram
      legend9->AddEntry(h10_2, "no neutrino", "l");
      legend9->SetTextSize(0.03); 
      legend9->Draw();

      TCanvas *c7 = new TCanvas();
      h11->Draw();
      h11_2->Draw("SAME");
      TLegend *legend10 = new TLegend(0.1, 0.7, 0.3, 0.9); 
      legend10->AddEntry(h11, "with", "l"); // "l" specifies line for histogram
      legend10->AddEntry(h11_2, "no neutrino", "l");
      legend10->SetTextSize(0.03); 
      legend10->Draw();

      TCanvas *c8 = new TCanvas();
      h12->Draw();
      h12_2->Draw("SAME");
      TLegend *legend11 = new TLegend(0.1, 0.7, 0.3, 0.9); 
      legend11->AddEntry(h12, "with", "l"); // "l" specifies line for histogram
      legend11->AddEntry(h12_2, "no neutrino", "l");
      legend11->SetTextSize(0.03); 
      legend11->Draw();

      TCanvas *c9 = new TCanvas();
      h13->Draw();
      h13_2->Draw("SAME");
      TLegend *legend15 = new TLegend(0.1, 0.7, 0.3, 0.9); 
      legend15->AddEntry(h13, "with", "l"); // "l" specifies line for histogram
      legend15->AddEntry(h13_2, "no neutrino", "l");
      legend15->SetTextSize(0.03); 
      legend15->Draw();

      TCanvas *c10 = new TCanvas();
      h14->Draw();
      h14_2->Draw("SAME");
      TLegend *legend16 = new TLegend(0.1, 0.7, 0.3, 0.9); 
      legend16->AddEntry(h14, "with", "l"); // "l" specifies line for histogram
      legend16->AddEntry(h14_2, "no neutrino", "l");
      legend16->SetTextSize(0.03); 
      legend16->Draw();


      h16_2-> SetLineColor(kRed);
      h15_2-> SetLineColor(kRed);

      TCanvas *c11 = new TCanvas();
      h15->Draw();
      h15_2->Draw("SAME");
      TLegend *legend14 = new TLegend(0.1, 0.7, 0.3, 0.9); 
      legend14->AddEntry(h15, "with", "l"); // "l" specifies line for histogram
      legend14->AddEntry(h15_2, "no neutrino", "l");
      legend14->SetTextSize(0.03); 
      legend14->Draw();
      
      TCanvas *c12 = new TCanvas();
      h16->Draw();
      h16_2->Draw("SAME");
      TLegend *legend17 = new TLegend(0.1, 0.7, 0.3, 0.9); 
      legend17->AddEntry(h16, "with", "l"); // "l" specifies line for histogram
      legend17->AddEntry(h16_2, "no neutrino", "l");
      legend17->SetTextSize(0.03); 
      legend17->Draw();


   // TCanvas *c_gennewPtless = new TCanvas();
    // h_newPtless->Draw();

      h17-> SetLineColor(kRed);
      h18-> SetLineColor(kRed);

      TCanvas *c_genPt = new TCanvas();
      h17->Draw(); 
      h17_2->Draw("SAME");
      TLegend *legend18 = new TLegend(0.1, 0.7, 0.3, 0.9); 
      legend18->AddEntry(h17, "With neutrino", "l"); // "l" specifies line for histogram
      legend18->AddEntry(h17_2, "No neutrino", "l");
      legend18->SetTextSize(.03); 
      legend18->Draw();
      TCanvas *c_recoPt = new TCanvas();
      h18->Draw(); 
      h18_2->Draw("SAME");
      TLegend *legend19 = new TLegend(0.1, 0.7, 0.3, 0.9); 
      legend19->AddEntry(h18, "With neutrino", "l"); // "l" specifies line for histogram
      legend19->AddEntry(h18_2, "No neutrino", "l");
      legend19->SetTextSize(.03); 
      legend19->Draw();

    /*TCanvas *c_isGenZero = new TCanvas();
     h_isGenPhiZero->Draw();
    TCanvas *c_isGenZeroY = new TCanvas();
     h_isGenPhiZeroY->Draw();*/
   /*TCanvas *c_cmsPt = new TCanvas();
     h_CMSPt->Draw();
    TCanvas *c_cmsPhi = new TCanvas();
     h_CMSPhi->Draw(); */

      h_CMSPt-> SetLineColor(kRed);
      h_CMSPhi-> SetLineColor(kRed);
      h_lessRecoPt-> SetLineColor(kRed);
     // h_nuEtaL->SetLineColor(kRed);
      h_nuPhiless->SetLineColor(kRed);
      h_nuPtless->SetLineColor(kRed);



      TCanvas *c_cmsPt = new TCanvas();
      h_CMSPt->Draw(); 
      h_CMSPt2->Draw("SAME");
      TLegend *legend20 = new TLegend(0.1, 0.7, 0.3, 0.9); 
      legend20->AddEntry(h_CMSPt, "With neutrino", "l"); // "l" specifies line for histogram
      legend20->AddEntry(h_CMSPt2, "No neutrino", "l");
      legend20->SetTextSize(.03); 
      legend20->Draw();

      TCanvas *c_cmsPhi = new TCanvas();
      h_CMSPhi->Draw(); 
      h_CMSPhi2->Draw("SAME");
      TLegend *legend21 = new TLegend(0.1, 0.7, 0.3, 0.9); 
      legend21->AddEntry(h_CMSPhi, "with neutrino", "l"); // "l" specifies line for histogram
      legend21->AddEntry(h_CMSPhi2, "no neutrino", "l");
      legend21->SetTextSize(.03); 
      legend21->Draw(); 

      TCanvas *creco1 = new TCanvas();
       h_moreRecoPt->Draw();    
       h_lessRecoPt->Draw("SAME");
      TLegend *legend13 = new TLegend(0.1, 0.7, 0.3, 0.9); 
      legend13->AddEntry(h_moreRecoPt, "more", "l"); // "l" specifies line for histogram
      legend13->AddEntry(h_lessRecoPt, "less", "l");
      legend13->SetTextSize(.03); 
      legend13->Draw(); 

      TCanvas *creco2 = new TCanvas();
       h_nuPhi->Draw();
       h_nuPhiless->Draw("SAME");
      TLegend *legend13 = new TLegend(0.1, 0.7, 0.3, 0.9); 
      legend13->AddEntry(h_nuPhi, "more", "l"); // "l" specifies line for histogram
      legend13->AddEntry(h_nuPhiless, "less", "l");
      legend13->SetTextSize(.03); 
      legend13->Draw(); 

       TCanvas *creco3 = new TCanvas();
       h_nuEta->Draw();
     // h_nuEtaL->Draw("SAME");
      TLegend *legend13 = new TLegend(0.1, 0.7, 0.3, 0.9); 
      legend13->AddEntry(h_nuEta, "more", "l"); // "l" specifies line for histogram
    //  legend13->AddEntry(h_nuEtaL, "less", "l");
      legend13->SetTextSize(.03); 
      legend13->Draw(); 

    TCanvas *cnuPt = new TCanvas();
      h_nuPt->Draw();
      h_nuPtless->Draw("SAME");
      TLegend *legend13 = new TLegend(0.1, 0.7, 0.3, 0.9); 
      legend13->AddEntry(h_nuPt, "more", "l"); // "l" specifies line for histogram
      legend13->AddEntry(h_nuPtless, "less", "l");
      legend13->SetTextSize(.03); 
      legend13->Draw(); 
  

      TCanvas *cnuPtEta = new TCanvas();
      hPtEta->Draw("COLZ");
       TCanvas *cnuPtEtaless = new TCanvas();
      hPtEta_less->Draw("COLZ");
        TCanvas *crecogenPt = new TCanvas("crecogenPt");
      hRecoGenPt->Draw("COLZ");


c->SaveAs("C:/Users/user/Desktop/RecoGen_pt.png");    
c1->SaveAs("C:/Users/user/Desktop/RecoGen_eta.png");
c2->SaveAs("C:/Users/user/Desktop/RecoGen_phi.png");
cpx->SaveAs("C:/Users/user/Desktop/Gen_px.png");
cpy->SaveAs("C:/Users/user/Desktop/Gen_py.png");
cpx_reco->SaveAs("C:/Users/user/Desktop/Reco_px.png");
cpy_reco->SaveAs("C:/Users/user/Desktop/Reco_py.png");
c7->SaveAs("C:/Users/user/Desktop/Gen_pnx.png");
c8->SaveAs("C:/Users/user/Desktop/Gen_pny.png");
c9->SaveAs("C:/Users/user/Desktop/Reco_pnx.png");
c10->SaveAs("C:/Users/user/Desktop/Reco_pny.png"); 
c11->SaveAs("C:/Users/user/Desktop/genPt_new.png");
c11_2->SaveAs("C:/Users/user/Desktop/genPt_new-no.png");
c12->SaveAs("C:/Users/user/Desktop/genPhi_new.png");
c_genPt->SaveAs("C:/Users/user/Desktop/recoPt_new.png");
c_recoPt->SaveAs("C:/Users/user/Desktop/recoPhi_new.png");
c_cmsPt->SaveAs("C:/Users/user/Desktop/CMS_effPt.png");
c_cmsPhi->SaveAs("C:/Users/user/Desktop/CMS_effPhi.png");
c2_2->SaveAs("C:/Users/user/Desktop/RecoGen_pt-no.png");    
c1_2->SaveAs("C:/Users/user/Desktop/RecoGen_eta-no.png");
c2_2->SaveAs("C:/Users/user/Desktop/RecoGen_phi-no.png");
creco1->SaveAs("C:/Users/user/Desktop/MoreVLessRecoPt.png");    
creco2->SaveAs("C:/Users/user/Desktop/NuPhi.png");
creco3->SaveAs("C:/Users/user/Desktop/NuEta.png");
cnuPt->SaveAs("C:/Users/user/Desktop/NuPt.png");    
cnuPtEta->SaveAs("C:/Users/user/Desktop/NuPtEtaMore.png");    
cnuPtEtaless->SaveAs("C:/Users/user/Desktop/RecoGen_eta-no.png");


}
