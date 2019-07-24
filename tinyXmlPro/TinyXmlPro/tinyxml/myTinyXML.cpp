#include "myTinyXML.h"
#include <iostream>
void TestTinyXMLLoad(void)
{
    TiXmlDocument doc;
    if(!doc.LoadFile("test.xml"))
    {
        std::cout << "Load test.xml file failed." << std::endl;
        const char *errorStr = doc.ErrorDesc();
        std::cout << errorStr << std::endl;
    }
    else
    {
        //成功打开XML文件
        std::cout << "Load test.xml file success." << std::endl;

        //获取根节点
        TiXmlElement *root = doc.RootElement();
        TiXmlElement *studentsElement = root->FirstChildElement();
        TiXmlElement *studentElement = studentsElement->FirstChildElement();

        //遍历
        //TiXmlAttribute *rootAttribute = root->FirstAttribute();
        //for(rootAttribute; rootAttribute != NULL; rootAttribute = rootAttribute->Next())
        while(studentElement)
        {
            TiXmlAttribute* attributeOfStudent = studentElement->FirstAttribute();
            while(attributeOfStudent)
            {
                std::cout << attributeOfStudent->Name() << " : " << attributeOfStudent->Value() << std::endl;
                attributeOfStudent = attributeOfStudent->Next();
            }
            TiXmlElement* phoneElemt = studentElement->FirstChildElement();
            std::cout << "phone : " << phoneElemt->GetText() << std::endl;
            TiXmlElement* addressElemt = phoneElemt->NextSiblingElement();
            std::cout << "address : " << addressElemt->GetText() << std::endl;
            studentElement = studentElement->NextSiblingElement();
        }
    }
}

void TestTinyXMLParse(void)
{
    std::cout << "Enter the TestTinyXMLParse" << std::endl;
    TiXmlDocument doc;
    TiXmlElement* root = new TiXmlElement("Class");
    doc.LinkEndChild(root);
    TiXmlElement* Students = new TiXmlElement("Students");
    root->LinkEndChild(Students);

    TiXmlElement* student;
    student = new TiXmlElement("student");
    Students->LinkEndChild(student);

    student->SetAttribute("name", "zhangsan");
    student->SetAttribute("age", "22");
    student->SetAttribute("sex", "male");
    student->SetAttribute("studentNo", "1410");
    TiXmlElement* phone;
    phone = new TiXmlElement("phone");
    phone->LinkEndChild(new TiXmlText("8828666"));
    student->LinkEndChild(phone);
    TiXmlElement* address;
    address = new TiXmlElement("address");
    address->LinkEndChild(new TiXmlText("308shi"));
    student->LinkEndChild(address);
    ///*
    std::cout << "djjjjjjjjjjjjjjjj" << std::endl;
    student = new TiXmlElement("student");
    Students->LinkEndChild(student);
    std::cout << "jouoooooooooooop" << std::endl;
    student->SetAttribute("name", "lisi");
    student->SetAttribute("age", "21");
    student->SetAttribute("sex", "female");
    student->SetAttribute("studentNO", "1411");
    phone = new TiXmlElement("phone");
    phone->LinkEndChild(new TiXmlText("8827887"));
    student->LinkEndChild(phone);
    address = new TiXmlElement("address");
    address->LinkEndChild(new TiXmlText("317shi"));
    student->LinkEndChild(address);
    //*/
    /*
    TiXmlElement* student1;
    student1 = new TiXmlElement("student");
    Students->LinkEndChild(student1);

    student1->SetAttribute("name", "lisi");
    student1->SetAttribute("age", "21");
    student1->SetAttribute("sex", "female");
    student1->SetAttribute("studentNo", "1411");
    TiXmlElement* phone1 = new TiXmlElement("phone");
    phone1->LinkEndChild(new TiXmlText("8827887"));
    student1->LinkEndChild(phone1);
    TiXmlElement* address1 = new TiXmlElement("address");
    address1->LinkEndChild(new TiXmlText("317shi"));
    student1->LinkEndChild(address1);
    */
    std::cout << "lllllllllllllll" << std::endl;
    doc.SaveFile("testparse.xml");
}
