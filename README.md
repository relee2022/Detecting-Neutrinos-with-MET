# Detecting-Neutrinos-with-MET & Transverse Mass
rootAnalyzer.C is worked up to pp collisions with neutrinos and only reading and comparing gen and reco of one file.

rootAnalyzerEdited.C is comparing and graphing files containing 10k events of pp collisons with and without neutrinos. Calculating the misisng mommentum of the neutrinos and comparing Gen and Reco to determine if CMS is being efficient. We're seeing Reco outdo gen's Pt with the file containing neutrinos and data is indiciating we may not be detecting neutrinos with a charge of 0.

The rest of the files piggy back off of rootAnalyzerEdited but gets closer and closer to final product of Missing Momementum Pt Reco-Gen being close to the Value of 0 (creater narrower plots of pt cuts 1-5 . Greater than 4 GeV making the best resolution cut for the comparison of CMS detecter.) Also plotted the transverse mass of data, which gets us close to the measurement of the W boson=80.377. We then moved on to an heavy ion collision specifically PbPb and calculated it's missing momentum along with the transverse mass of the W boson. Pt cut of 5 GeV gives best resolution for CMS.
