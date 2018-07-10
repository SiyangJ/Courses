//
//  main.cpp
//  COMP411
//
//  Created by apple on 11/4/17.
//  Copyright © 2017 UNC. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    bool x[] = {0,0,0,0,1,1,1,1};
    bool y[] = {0,0,1,1,0,0,1,1};
    bool z[] = {0,1,0,1,0,1,0,1};
    
    vector<vector<bool>> XYZ = {
        {0,0,0,0,1,1,1,1},
        {0,0,1,1,0,0,1,1},
        {0,1,0,1,0,1,0,1}};
    /*
    vector<vector<bool>> funcs = {
        {0,0,0,1,1,1,0,1},
        {0,0,1,1,0,0,0,0},
        {1,0,0,0,0,0,0,0},
        {0,1,1,1,1,0,0,0},
        {1,0,0,0,1,0,0,0}};
    */
    
    /*
    bool x[] = {0,0,0,0,1,1,1,1};
    bool y[] = {0,0,1,1,0,0,1,1};
    bool z[] = {0,1,0,1,0,1,0,1};
    */
    
    /*
    vector<vector<bool>> funcs = {
        {0,0,0,1,1,0,1,1},
        {1,1,0,0,1,1,1,1},
        {1,1,1,1,0,0,0,0},
        {1,0,0,0,0,0,0,0},
        {1,0,1,0,0,1,1,0}};
    */
    
    
    vector<vector<bool>> funcs = {
        {1,1,1,0,1,1,0,0},
        {1,1,0,0,1,1,1,1},
        {1,1,1,0,0,0,0,0},
        {1,0,1,0,0,1,1,0},
        {1,1,0,1,1,1,0,1}};
    
    
    // AND NAND OR XOR NOR XNOR ONE ZERO
    
    /*
    
    for (int i=0;i<5;i++)
    {
        for (int j=0;j<8;j++)
        {
            bool* K,*I,*J;
            
            for (int k=0;k<3;k++)
            {
                
                bool yes=true;
                bool intm;
                switch (k) {
                    case 0:
                        K=x;
                        I=y;
                        J=z;
                        break;
                    case 1:
                        K=y;
                        I=x;
                        J=z;
                        break;
                    case 2:
                        K=z;
                        I=y;
                        J=x;
                        break;
                }
                
                for (int l=0;l<8;l++)
                {
                    switch (j) {
                        case 0:
                            intm=I[l]&J[l];
                            break;
                        case 1:
                            intm=!(I[l]&J[l]);
                            break;
                        case 2:
                            intm=I[l]|J[l];
                            break;
                        case 3:
                            intm=I[l]^J[l];
                            break;
                        case 4:
                            intm=!(I[l]|J[l]);
                            break;
                        case 5:
                            intm=!(I[l]^J[l]);
                            break;
                        case 6:
                            intm=1;
                            break;
                        case 7:
                            intm=0;
                            break;

                    }
                    
                    if ((K[l]^intm)!=funcs[i][l])
                    {
                        yes=false;
                        cout << "False at "<< i << ' ' << j << ' ' << k << ' ' << l<< endl;
                        break;
                    }
                    
                }
                
                if (yes)
                {
                    cout << i << ' ' << j << ' ' << k << endl;
                }
                
            }
            
        }
    }
     
     */
    
    for (int i=0;i<5;i++)
    {
        for (int j=0;j<3;j++)
        {
            vector<bool> pos;
            for (int k=0;k<8;k++)
            {
                pos.push_back(funcs[i][k]?!XYZ[j][k]:XYZ[j][k]);
            }
            bool can=true;
            switch (j) {
                case 0:
                    for (int k=0;k<4;k++)
                    {
                        if (pos[k]!=pos[k+4])
                        {
                            can=false;
                            break;
                        }
                    }
                    break;
                case 1:
                    if (pos[0]!=pos[2]||
                        pos[1]!=pos[3]||
                        pos[4]!=pos[6]||
                        pos[5]!=pos[7]
                        )
                        can=false;
                    break;
                case 2:
                    if (pos[0]!=pos[1]||
                        pos[2]!=pos[3]||
                        pos[4]!=pos[5]||
                        pos[6]!=pos[7]
                        )
                        can=false;
                    break;
            }
            if (can)
            {
                cout << i << ' ' << j << endl;
                for (int k=0;k<8;k++)
                {
                    cout << pos[k] << ' ';
                }
                cout << endl;
            }
        }
    }
    
    
    
    
    
}
