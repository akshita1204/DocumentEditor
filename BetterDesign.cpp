#include<bits/stdc++.h>
using namespace std;

//Abstraction for document element
class DocumentElement
{
public:
virtual string render()=0;
};
//implementation for text element
class TextElement : public DocumentElement
{
    private:
    string text;
    public:
    TextElement(string text)
    {
      this->text=text;
    }
    string render() override
    {
       return text;
    }
};

//implementation for image element
class ImageElement : public DocumentElement
{
    private:
    string imagepath;
    public:
    ImageElement(string imagepath)
    {
      this->imagepath=imagepath;
    }
    string render() override
    {
       return "[ Image" + imagepath + "]";
    }
};

//new line elemment represents a line break in the document
class NewLineElement : public DocumentElement
{
  public:
  string render() override
  {
    return "\n";
  }
};
//tab line elemment represents a tab in the document
class TabSpaceElement : public DocumentElement
{
  public:
  string render() override
  {
    return "\t";
  }
};

//Document class is res for holding a collection of elements
class Document
{
private:
vector<DocumentElement*>docElements;
public:
void addElement(DocumentElement* element)
{
  docElements.push_back(element);
}
string render() 
{
    string res;
    for(auto ele:docElements)
    {
        res+=ele->render();
    }
    return res;
}
};

class Persistence
{
 public:
 virtual void save(string data)=0;
};

class FileStorage: public Persistence{
    public:
    void save(string data) override
    {
       ofstream outfile("documenet1.txt");
       if(outfile)
       {
        outfile<<data;
        outfile.close();
        cout<<"Document saveed to the document1.txt"<<endl;
       }
       else
       {
        cout<<"Not Saved"<<endl;
       }
    }
};

class DbStorage : public Persistence
{
public: 
 void save(string data) override
    {
       //save to b
    }

};

class DocumentEditor
{
private:
Document* document;
Persistence* storage;
string renderDoc;
public:
DocumentEditor(Document* document, Persistence* storage)
{
    this->document=document;
    this->storage=storage;
}
void addText(string text)
{
    document->addElement(new TextElement(text));
}
void addImage(string imagePath)
{
    document->addElement(new TextElement(imagePath));
}
void addNewLine()
{
    document->addElement(new NewLineElement());
}
void addTabSpace()
{
    document->addElement(new TabSpaceElement());
}
string renderDocument()
{
    if(renderDoc.empty())
    {
        renderDoc=document->render();
    }
    return renderDoc;
}
void saveDoc()
{
    storage->save(renderDocument());
}
};

int main()
{
  Document* document=new Document();
  Persistence* persistence=new FileStorage();
  DocumentEditor* editor=new DocumentEditor(document,persistence);

  editor->addText("Hello!");
  editor->addNewLine();
  editor->addText("world");
  editor->addNewLine();
  editor->addTabSpace();
  editor->addText("Welcome");
  editor->addNewLine();
  editor->addImage("pic.png");

  cout<<editor->renderDocument()<<endl;
  editor->saveDoc();
  return 0;
}