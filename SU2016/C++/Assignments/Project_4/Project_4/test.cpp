//
//  main.cpp
//  Project_4
//
//  Created by apple on 8/4/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include "Game.h"
#include "Player.h"

using namespace std;

const char* filename = "/Users/wq/Desktop/SU2016/C++/Assignments/Project_4/wordlist.txt";
// A Windows user might have the path be "C:/CS32/P4/wordlist.txt"
// A Mac user might have it be "/Users/fred/CS32/P4/wordlist.txt"

int play(Game& g, Player &p)
{
    int secretLength = g.secretWordLength();
    int nTurns = 0;
    time_t t1,t2;
    for(;;)
    {
        int nInRightPlace, nInWrongPlace;
        string probe = p.generateProbeWord();
        time(&t1);
        g.probe(probe, nInRightPlace, nInWrongPlace);
        time(&t2);
        if (t2-t1>5) cerr << "Error! Too much time!" << endl;
        // repeat probes until word is guessed
        nTurns++;
        if (nInRightPlace == secretLength)
            break;
        time(&t1);
        p.learn(probe, nInRightPlace, nInWrongPlace);
        time(&t2);
        if (t2-t1>5) cerr << "Error! Too much time!" << endl;
    }
    
    cerr << "The Player probed " << nTurns << " times!" << endl;
    return nTurns;
}

int main()
{
    ifstream wordlistfile(filename);
    if (!wordlistfile)
    {
        cerr << "Cannot open " << filename << "!" << endl;
        return 1;
    }
    vector<string> words;
    
    string w;
    while (wordlistfile >> w)
        words.push_back(w);
    const unsigned int MAX_TEST_NUM=50;
    int count=0;
    for (int i=0;i<MAX_TEST_NUM;i++){
        string secWord = words[rand()%words.size()];
    Player player(words);
    Game g(words);
    
    if (!g.setSecretWord(secWord))  // Supply the secret word
    {
        cerr << "Secret word is not in word list!" << endl;
        return 1;
    }
    
    count+=play(g, player);
    }
    cout << static_cast<double>(count)/MAX_TEST_NUM << endl;
}
