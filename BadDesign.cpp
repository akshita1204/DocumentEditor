
#include<bits/stdc++.h>
using namespace std;
class DocumentEditor
{
    public:
    vector<string>docElement;
    string renderDocument;

    public:
    //to add the text
    void addText(string text)
    {
        docElement.push_back(text);
    }
    //to add the image
    void addImage(string text)
    {
        docElement.push_back(text);
    }
    //render the documnent by checking the type of each element
    string renderDoc()
    {
        if(renderDocument.empty())
        {
            string res;
            for(auto ele:docElement)
            {
                if(ele.size()>4 && (ele.substr(ele.size()-4)==".jpg" or ele.substr(ele.size()-4)==".png"))
                {
                    res+="[Image: "  + ele + "]" + "\n";
                }
                else{
                    res+=ele + "\n";
                }
            }
            renderDocument=res;
        }
        return renderDocument;
    }

    void saveFile()
    {
        ofstream file("Document.txt");
        if(file.is_open())
        {
            file<< renderDoc();
            file.close();
            cout<<"Document saved to document.txt"<<endl;
        }
        else
        {
            cout<<"Unable to write on the file"<<endl;
        }
    }
};

int main()
{
    DocumentEditor editor;
    editor.addText("hello,world");
    editor.addImage("picture.png");
    editor.addText("welcome!");
    cout<<editor.renderDoc()<<endl;
    editor.saveFile();
    return 0;

}
