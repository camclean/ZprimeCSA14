// -*- C++ -*-
//
// Package:    Analysis/processMiniAOD
// Class:      processMiniAOD
// 
/**\class processMiniAOD processMiniAOD.cc Analysis/processMiniAOD/plugins/processMiniAOD.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  christine mclean
//         Created:  Wed, 23 Jul 2014 14:45:53 GMT
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDFilter.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

//
// class declaration
//

class processMiniAOD : public edm::EDFilter {
   public:
      explicit processMiniAOD(const edm::ParameterSet&);
      ~processMiniAOD();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

   private:
      virtual void beginJob() override;
      virtual bool filter(edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;
      
      //virtual void beginRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void endRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;
      //virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;

      // ----------member data ---------------------------

  edm::InputTag     AK8jetSrc_;
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
processMiniAOD::processMiniAOD(const edm::ParameterSet& iConfig):
  AK8jetSrc_      (iConfig.getParameter<edm::InputTag>("AK8jetSrc") )
{
   //now do what ever initialization is needed

}


processMiniAOD::~processMiniAOD()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called on each new Event  ------------
bool
processMiniAOD::filter(edm::Event& iEvent, const edm::EventSetup& iSetup)
{

  edm::Handle<std::vector<pat::Jet> > h_AK8jet;

  iEvent.getByLabel( AK8jetSrc_, h_AK8jet );

  for ( std::vector<pat::Jet>::const_iterator jetBegin = h_wTag->begin(), jetEnd = h_wTag->end(), ijet = jetBegin; ijet != jetEnd; ++ijet ) {
    cout ijet.pt();
  }

   using namespace edm;
#ifdef THIS_IS_AN_EVENT_EXAMPLE
   Handle<ExampleData> pIn;
   iEvent.getByLabel("example",pIn);
#endif

#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
#endif
   return true;
}

// ------------ method called once each job just before starting event loop  ------------
void 
processMiniAOD::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
processMiniAOD::endJob() {
}

// ------------ method called when starting to processes a run  ------------
/*
void
processMiniAOD::beginRun(edm::Run const&, edm::EventSetup const&)
{ 
}
*/
 
// ------------ method called when ending the processing of a run  ------------
/*
void
processMiniAOD::endRun(edm::Run const&, edm::EventSetup const&)
{
}
*/
 
// ------------ method called when starting to processes a luminosity block  ------------
/*
void
processMiniAOD::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/
 
// ------------ method called when ending the processing of a luminosity block  ------------
/*
void
processMiniAOD::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/
 
// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
processMiniAOD::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}
//define this as a plug-in
DEFINE_FWK_MODULE(processMiniAOD);
