#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

//字符串分割函数
//str 输入字符串 delim 分割字符
vector<string> string_split(const string& str, const string& delim) 
{
    vector<string> res;
    if("" == str) return res;
    //先将要切割的字符串从string类型转换为char*类型
    char * strs = new char[str.length() + 1] ; //不要忘了
    strcpy(strs, str.c_str());
  
    char * d = new char[delim.length() + 1];
    strcpy(d, delim.c_str());
  
    char *p = strtok(strs, d);
    while(p) {
        string s = p; //分割得到的字符串转换为string类型
        res.push_back(s); //存入结果数组
        p = strtok(NULL, d);
    }
  
    return res;
}

//判断字符串是否是数字
bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

int main()
{
    cout << "请输入两个整数，用,隔开" << endl;
    char data[50];
    cin >> data;
    cout << "input data:" << data << endl;
    vector<string> data_str_vec;
    const string char_delim = ",";
    data_str_vec = string_split(data,char_delim);
    if(data_str_vec.size() != 2)
    {
        cerr << "输入参数数量错误," << data_str_vec.size() << endl;
        return 0;
    }
    string data1 = data_str_vec[0];
    string data2 = data_str_vec[1];
    if(!isNumber(data1) || !isNumber(data2))
    {
        cerr << "输入数据类型错误" << endl;
        return 0;
    }
    int int_data1 = atoi(data1.c_str());
    int int_data2 = atoi(data2.c_str());
    int result = int_data1 + int_data2;
    cout << "输出结果:" << result << endl;
}