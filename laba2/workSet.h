namespace {
    const std::string Universum = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string delRep(std::string str) {
        std::string res;
        for (auto x:str) {
            if ((isprint(x) && isupper(x) && (res.find(x)) == std::string::npos)) {
                res += x;
            }
        }
        return res;

    }
    std::string inputStr(char name) {
        std::string res;
        std::cout<<"Введите множество "<<name<<": ";
        std::cin >> res;
        return (delRep(res));
    }
    std::string randStr() {
        std::string res;
        for (auto x:Universum)
            if (rand()% 2) {
                res += x;
            }
        return res;
    }
    void outputSet(MathSet out)
    {
        std::cout<<"Множество "<<out.getName()<<": "<<out<<'\n';

    }
}