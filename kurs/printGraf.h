#include <fstream>
#include <iostream>
#include <vector>
void readtxt(std::vector<int> &arr,std::vector<int> &arr2,char *name)
{
    std::ifstream in(name);
    int temp=0;
    while (in)
    {   in>>temp;
        arr.push_back(temp);
        in>>temp;
        arr2.push_back(temp);

    }
    in.close();
}
void writegv(std::vector<int> &arr,std::vector<int> &arr2,char *name)
{
    std::ofstream out(name);
    out << "graph s {\n";
    int k=arr.size()-1;
    for (int i=0;i<k;i++)
    {
        if((arr[i])!=0)
            out<<arr[i]<<"--"<<arr2[i]<<";\n";
    }
    out<<"}";
    out.close ();
}
void printG(){

    std::vector<int> arr;
    std::vector<int> arr2;

    readtxt(arr,arr2,"input.txt");
    writegv(arr,arr2,"inGv.gv");
    system("circo -Tpng inGv.gv -output.png");
    arr.clear();
    arr2.clear();
    readtxt(arr,arr2,"output.txt");
    writegv(arr,arr2,"outGv.gv");
    system("circo -Tpng outGv.gv -output2.png");
}

