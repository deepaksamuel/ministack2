//g++  `root-config --glibs --cflags` ino_analysis.cpp main.cpp
//./a.out
#include <TTree.h>
#include <TFile.h>
#include <iostream>
#include  "ino_analysis.h"





using namespace::std;
int main()
{
    TString input ="INORUN_20161230_161712.ire"; // input file
    //output will be stored as out.fit.// This name can be changed in ino_analysis.cpp
  
    
    TFile *file = new TFile(input);
    TTree *T = (TTree*)file->Get("evetree");
    int N= T->GetEntries();
    cout<<N<<" entries in file "<<input<<endl;

    ino_analysis *a = new ino_analysis(T);
    a->Init(T);
    a->SlaveBegin(T);
    
    for (int i=0;i<N;i++){
    a->Process(i);
    if(i%5000==0)
    cout<<i<<" entries processed..."<<endl;
    }

    cout<<"Processing completed..."<<endl;
    a->SlaveTerminate();



    return 0;
}