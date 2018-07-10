//
//  test.cpp
//  HW_3
//
//  Created by apple on 7/19/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

//Your declarations and implementations would go here

class SmartPhone
{
public:
    SmartPhone(string name):m_name(name){}
    string name() const
    {
        return m_name;
    }
    virtual string futureMove() const =0;
    //{
    //    return m_futureMove;
    //}
    virtual void printWebBrowser() const =0;
    //{
    //    cout << m_webBrowser;
    //}
    void destroy() const
    {
        cout << "Destroying " << m_name << " the ";
    }
    virtual ~SmartPhone(){}
    
private:
    string m_name;
    //string m_futureMove;
    //string m_webBrowser;
};

class Windows : public SmartPhone
{
public:
    Windows(string name):SmartPhone(name){}
    virtual string futureMove() const
    {
        return "tries to maintain its market share";
    }
    virtual void printWebBrowser() const
    {
        cout << "IE";
    }
    virtual ~Windows()
    {
        destroy();
        cout << "Windows\n";
    }
};

class Android : public SmartPhone
{
public:
    Android(string name):SmartPhone(name){}
    virtual string futureMove() const
    {
        return "tries to gain market share";
    }
    virtual void printWebBrowser() const
    {
        cout << "Chrome";
    }
    virtual ~Android()
    {
        destroy();
        cout << "Android\n";
    }
};

class iOS : public SmartPhone
{
public:
    iOS(string name,string version):SmartPhone(name),m_version(version){}
    virtual string futureMove() const
    {
        return "continues to lose market share";
    }
    virtual void printWebBrowser() const
    {
        cout << "Safari version " << m_version;
    }
    virtual ~iOS()
    {
        destroy();
        cout << "iOS\n";
    }
private:
    string m_version;
};


void availability(const SmartPhone* cp)
{
    cout << cp->name() << ", using ";
    cp->printWebBrowser();
    cout << ", " << cp->futureMove() << "." << endl;
}

int main()
{
    SmartPhone* phones[4];
    phones[0] = new Windows("Alcatel OneTouch Fierce XL with Windows 10");
    // iOS has a name and initial version number for the Safari Browser
    phones[1] = new iOS("iPhone 6 Plus", "10.0 beta 2");
    phones[2] = new Android("Samsung Galaxy S7");
    phones[3] = new Android("HTC 10");
    
    cout << "The SmartPhones availability!" << endl;
    for (int k = 0; k < 4; k++)
        availability(phones[k]);
    
    // Clean up the SmartPhones before exiting
    cout << "Cleaning up" << endl;
    for (int k = 0; k < 4; k++)
        delete phones[k];
}
