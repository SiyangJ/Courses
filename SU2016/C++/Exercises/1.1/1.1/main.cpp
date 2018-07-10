//
//  main.cpp
//  1.1
//
//  Created by 景思阳 on 16/5/29.
//  Copyright © 2016年 景思阳. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double weightOunce;
    const double tonOunce = 35273.92;
    
    cout << "PLease enter the weight of a package of breakfast cereal in ounces:\n";
    cin >> weightOunce;
    cout << "A package of breakfast cereal weighs " << (weightOunce/tonOunce) << " metric tons.\n"
         << round((tonOunce/weightOunce)) << " boxes are needed to yeild one metric ton of cereal.\n";
    
    return 0;
}
