#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

class PARSE_STRING{

public:

    virtual void ParsujXml() = 0;


};
class LOAD_READ:PARSE_STRING{

private:
       char c;
       int pos = 0;
       int start;
public:
    std::string myText;
    std::string SSS;

   void getFile(std::string filename)
    {
        std::ifstream MojFajl(filename);
        while (MojFajl.get(c)) SSS += c;
        MojFajl.close();
    }

    std::vector<std::string>getData(const std::string &text, std::string tag)
    {
        std::vector<std::string> collection;


        while (true)
        {
            start = text.find( "<" + tag, pos);
            if (start == std::string::npos)
                return collection;
            start = text.find( ">" , start);
            start++;

            pos = text.find("</" + tag, start);
            if (pos == std::string::npos)
                return collection;
            collection.push_back(text.substr( start, pos - start));

        }
    }

    void stripTags(std::string &text)
    {
        unsigned int start = 0, pos;

        while (start < text.size())
        {
            start = text.find( "<", start);
            if (start == std::string::npos)
                break;
            pos = text.find( ">", start);
            if (pos == std::string::npos)
                break;
            text.erase(start,pos - start + 1);
        }
    }
    void showTags(std::string &text)
    {
        unsigned int start = 0, pos;

        while (start < text.size())
        {
            start = text.find( "<", start);
            if (start == std::string::npos)
                break;
            pos = text.find( ">", start);
            if (pos == std::string::npos)
                break;
            text.erase(pos,(start+1) - pos);
        }


    }


   void ParsujXml(){ //early example of a solution
       //SSS.erase(std::remove(SSS.begin(), SSS.end(), ">" ), SSS.end());
      /* SSS.erase(std::remove(SSS.begin(), SSS.end(), '}'), SSS.end());
       SSS.erase(std::remove(SSS.begin(), SSS.end(), '"'), SSS.end());
       SSS.erase(std::remove(SSS.begin(), SSS.end(), '['), SSS.end());
       SSS.erase(std::remove(SSS.begin(), SSS.end(), ']'), SSS.end()); */

   };

};


int main() {

    LOAD_READ load; //konstruktor
    load.getFile("C:\\Users\\MILAN\\Desktop\\xml parser\\books.xml"); //change to your path

    std::string tag = "";

  //  std::cout << "unesite ime elementa koji vas zanima:\n";
   // std::string tag;
   // std::cin >>tag;

    bool stripOtherTags = true;

    std::string text = load.SSS;
    std::vector<std::string> all = load.getData(text, tag);
    for (std::string &s : all)
    {
        if (stripOtherTags){
             load.stripTags( s );
            //load.showTags(s);
            std::cout << s << '\n';
        }

    }
    return 0;
}
