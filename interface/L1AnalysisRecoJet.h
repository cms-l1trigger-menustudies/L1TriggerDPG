#ifndef __L1Analysis_L1AnalysisRecoJet_H__
#define __L1Analysis_L1AnalysisRecoJet_H__

//-------------------------------------------------------------------------------
// Created 05/03/2010 - A.C. Le Bihan
// 
//
// Original code : UserCode/L1TriggerDPG/L1RecoJetNtupleProducer - Jim Brooke
//-------------------------------------------------------------------------------

#include "DataFormats/JetReco/interface/CaloJetCollection.h"
#include "DataFormats/JetReco/interface/JetID.h"
#include "L1AnalysisRecoJetDataFormat.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"

class JetCorrector;

namespace L1Analysis
{
  class L1AnalysisRecoJet
  {
  public:
    L1AnalysisRecoJet();
    ~L1AnalysisRecoJet();
    
    //void Print(std::ostream &os = std::cout) const;
    void SetCaloJet(const edm::Event& event,
		    const edm::EventSetup& setup,
		    const edm::Handle<reco::CaloJetCollection> caloJets, 
		    edm::Handle<edm::ValueMap<reco::JetID> > jetsID,
		    const JetCorrector* jetCorrector,
		    unsigned maxJet);
    L1AnalysisRecoJetDataFormat * getData() {return &recoJet_;}
    void Reset() {recoJet_.Reset();}

  private :
    L1AnalysisRecoJetDataFormat recoJet_;
  }; 
}
#endif


