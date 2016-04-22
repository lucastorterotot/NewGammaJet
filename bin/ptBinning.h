#pragma once

#include <cmath>
#include <vector>
#include <utility>

class PtBinning {
  public:
    PtBinning() {
      fillPtBins();
    }

    int getPtBin(float pt) {
      std::vector<std::pair<float, float> >::const_iterator it = mPtBins.begin();
      for (; it != mPtBins.end(); ++it) {
        std::pair<float, float> bin = *it;
        if (pt >= bin.first && pt < bin.second) {
          return it - mPtBins.begin();
        }
      }

      return -1;
    }

    size_t size() const {
      return mPtBins.size();
    }

    std::pair<float, float> getBinValue(int bin) const {
      return mPtBins[bin];
    }

    std::vector<std::pair<float, float> > getBinning(int n = -1) const {
      if (n < 0) {
        n = size();
      }
      return std::vector<std::pair<float, float> >(mPtBins.begin(), mPtBins.begin() + n);
    }

    std::vector<std::pair<float, float> > getBinning(unsigned int from, unsigned int to) const {
      if (to > size()) {
        to = size();
      }

      return std::vector<std::pair<float, float> >(mPtBins.begin() + from, mPtBins.begin() + to);
    }

  private:
    std::vector<std::pair<float, float> > mPtBins;
/*
//for pfjet composition studies
  void fillPtBins() { // 2012
      mPtBins.push_back(std::make_pair(28, 37));
      mPtBins.push_back(std::make_pair(37, 49));
      mPtBins.push_back(std::make_pair(49, 64));
      mPtBins.push_back(std::make_pair(64, 84));
      mPtBins.push_back(std::make_pair(84, 114));
      mPtBins.push_back(std::make_pair(114, 153));
      mPtBins.push_back(std::make_pair(153, 196));
      mPtBins.push_back(std::make_pair(196, 245));
      mPtBins.push_back(std::make_pair(245, 300));
      mPtBins.push_back(std::make_pair(300, 395));
      mPtBins.push_back(std::make_pair(395, 468));
      mPtBins.push_back(std::make_pair(468, 548));
      mPtBins.push_back(std::make_pair(548, 686));
      mPtBins.push_back(std::make_pair(686, 846));
      mPtBins.push_back(std::make_pair(846, 1032));
      mPtBins.push_back(std::make_pair(1032, 1684));
      mPtBins.push_back(std::make_pair(1684, 2000));
    }
*/
 //for nominal g+j analysis
    void fillPtBins() { //2015
      
      // "official" - v2      
      
      mPtBins.push_back(std::make_pair(40., 50.));
      mPtBins.push_back(std::make_pair(50., 60.));
      mPtBins.push_back(std::make_pair(60., 85.));
      mPtBins.push_back(std::make_pair(85., 105.));
      mPtBins.push_back(std::make_pair(105., 130.));
      mPtBins.push_back(std::make_pair(130., 175.));
      mPtBins.push_back(std::make_pair(175., 230.));
      mPtBins.push_back(std::make_pair(230., 300.));
      mPtBins.push_back(std::make_pair(300., 400.));
      mPtBins.push_back(std::make_pair(400., 500.));
      mPtBins.push_back(std::make_pair(500., 700.));
      mPtBins.push_back(std::make_pair(700., 1000.));
      mPtBins.push_back(std::make_pair(1000.,1500.));      
      

      /*      
      mPtBins.push_back(std::make_pair(40., 60.));
      mPtBins.push_back(std::make_pair(60., 85.));
      mPtBins.push_back(std::make_pair(85., 100.));
      mPtBins.push_back(std::make_pair(100., 130.));
      mPtBins.push_back(std::make_pair(130., 175.));
      mPtBins.push_back(std::make_pair(175., 250.));
      mPtBins.push_back(std::make_pair(250., 300.));
      mPtBins.push_back(std::make_pair(300., 400.));
      mPtBins.push_back(std::make_pair(400., 500.));
      mPtBins.push_back(std::make_pair(500., 700.));
      mPtBins.push_back(std::make_pair(700., 1000.));
      mPtBins.push_back(std::make_pair(1000.,1500.));      
      */
      //mPtBins.push_back(std::make_pair(500., 1500.));      

      // Mikko's test
      // mPtBins.push_back(std::make_pair(40. , 180.));
      // mPtBins.push_back(std::make_pair(180. , 300.));
      // mPtBins.push_back(std::make_pair(300. , 1000.));

    } 
// //for nominal g+j analysis
//   void fillPtBins() {
//      mPtBins.push_back(std::make_pair(10., 5000.));
//   }
};
