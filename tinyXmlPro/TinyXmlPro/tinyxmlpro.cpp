#include "tinyxmlpro.h"
#include "ui_tinyxmlpro.h"


TinyXmlPro::TinyXmlPro(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TinyXmlPro)
{
    ui->setupUi(this);
}

TinyXmlPro::~TinyXmlPro()
{
    delete ui;
}

void TinyXmlPro::writexml(std::string xmlfile)
{
    TiXmlDocument doc;
    TiXmlElement* root = new TiXmlElement("Object");
    doc.LinkEndChild(root);
    root->SetAttribute("cols",1920);
    root->SetAttribute("rows",1080);
    TiXmlElement* images = new TiXmlElement("images");
    doc.LinkEndChild(images);
    TiXmlElement* image;
    TiXmlElement* resultPic;
    TiXmlElement* components;
    TiXmlElement* component;

    image = new TiXmlElement("image");
    images->LinkEndChild(image);
    image->SetAttribute("path","image1.jpg");
    image->SetAttribute("ID",1);
    image->SetAttribute("x",223);
    image->SetAttribute("y",444);
    image->SetAttribute("w",231);
    image->SetAttribute("h",43);

    resultPic = new TiXmlElement("resultPic");
    image->LinkEndChild(resultPic);
    resultPic->SetAttribute("path","reimage.jpg");

    components = new TiXmlElement("components");
    resultPic->LinkEndChild(components);
    components->SetAttribute("nut",1);
    components->SetAttribute("latch",0);
    components->SetAttribute("bolt",1);
    for(int i = 0; i < 2;i++)
    {
        component = new TiXmlElement("component");
        components->LinkEndChild(component);
        component->SetAttribute("path","component_name.jpg");
        component->SetAttribute("status","normal");
    }
    doc.SaveFile(xmlfile.c_str());
    std::cout << "write xml" << std::endl;
}

void TinyXmlPro::readxml(std::string xmlfile)
{
    TiXmlDocument doc;
    if(!doc.LoadFile(xmlfile.c_str()))
    {
        std::cout << "load the xml file failed." << std::endl;
        return;
    }
    TiXmlElement *root = doc.RootElement();
    std::cout << "Object: cols=" << atoi(root->Attribute("cols")) << ", rows=" << atoi(root->Attribute("rows")) << std::endl;
    TiXmlElement *images = root->NextSiblingElement();
    TiXmlElement *image = images->FirstChildElement();
    while(image)
    {
        std::cout << "image: path=" << image->Attribute("path") << ", ID=" << atoi(image->Attribute("ID")) << ", x=" <<
                     atoi(image->Attribute("x")) << ", y=" << atoi(image->Attribute("y")) << ", w=" <<
                     atoi(image->Attribute("w")) << ", h=" << atoi(image->Attribute("h")) << std::endl;
        TiXmlElement *resultPic = image->FirstChildElement();
        std::cout << "resultPic: path=" << resultPic->Attribute("path") << std::endl;
        TiXmlElement *components = resultPic->FirstChildElement();
        std::cout << "components: nut=" << atoi(components->Attribute("nut")) << ", latch=" <<
                     atoi(components->Attribute("latch")) << ", bolt=" << atoi(components->Attribute("bolt")) << std::endl;
        TiXmlElement *component = components->FirstChildElement();
        while(component)
        {
            std::cout << "component: path=" << component->Attribute("path") << ", status=" <<
                         component->Attribute("status") << std::endl;
            component = component->NextSiblingElement();
        }
        image = image->NextSiblingElement();
   }
    std::cout << "read xml" << std::endl;
}
