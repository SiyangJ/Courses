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
#include "Game.h"
#include "Player.h"

using namespace std;

const char* filename = "/Users/wq/Desktop/SU2016/C++/Assignments/Project_4/wordlist.txt";
// A Windows user might have the path be "C:/CS32/P4/wordlist.txt"
// A Mac user might have it be "/Users/fred/CS32/P4/wordlist.txt"

void play(Game& g, Player &p)
{
    int secretLength = g.secretWordLength();
    int nTurns = 0;
    for(;;)
    {
        int nInRightPlace, nInWrongPlace;
        string probe = p.generateProbeWord();
        g.probe(probe, nInRightPlace, nInWrongPlace);
        // repeat probes until word is guessed
        nTurns++;
        if (nInRightPlace == secretLength)
            break;
        p.learn(probe, nInRightPlace, nInWrongPlace);
    }
    
    cerr << "The Player probed " << nTurns << " times!" << endl;
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
    
    Player player(words);
    Game g(words);
    
    if (!g.setSecretWord("involuntary"))  // Supply the secret word
    {
        cerr << "Secret word is not in word list!" << endl;
        return 1;
    }
    
    play(g, player);
}
