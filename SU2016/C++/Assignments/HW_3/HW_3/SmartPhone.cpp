//
class SmartPhone
{
public:
    SmartPhone(string name):m_name(name){}
    string name() const
    {
        return m_name;
    }
    virtual string futureMove() const =0;
    //first const then =0!!!
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
    //Destructor cannot pure virtual
    
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