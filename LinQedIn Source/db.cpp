/*
    This software was inspired by Linkedin as desired to simulate a service 
    where registered users can join together through a network of friends.
	The purpose of this project is to create software that exploits as much as possible 
	the concept of polymorphism and inheritance using the MVC design pattern.
    Copyright (C) 2016  Davide Rigoni

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include "db.h"


DB::DB(const QString& path)
{
    this->DBPath="";
    this->Load(path);
}

DB::~DB()
{
    //svuoto il vettore di utenti deallocandoli dallo heap
    for(QMap<QString,AUser*>::iterator it=users.begin();it!=users.end();++it)
    {
        delete it.value();
    }
}


//------------------METODI PRIVATI------------------------
void DB::clearDB()
{
    //svuoto il vettore di utenti deallocandoli dallo heap
    for(QMap<QString,AUser*>::iterator it=users.begin();it!=users.end();++it)
    {
        delete it.value();
    }
    this->users.clear();
    this->DBPath = "";
}


//-------------------METODI PUBBLICI--------------------
//iteratori
QMap<QString,AUser*>::iterator DB::Begin()
{
    return users.begin();
}

QMap<QString,AUser*>::const_iterator DB::ConstBegin()const
{
    return users.constBegin();
}

QMap<QString,AUser*>::iterator DB::End()
{
    return users.end();
}

QMap<QString,AUser*>::const_iterator DB::ConstEnd()const
{
    return users.constEnd();
}



bool DB::Load(const QString& path)
{
    //verifico se c'è già un database caricato
    if(!IsLoad())
    {
        //salvo la path del database
        this->DBPath = path;

        //apertura file e dello stream
        QFile file(path);
        if(!file.open(QFile::ReadOnly | QFile::Text))
        {
            file.close();
            return false;
        }
        QXmlStreamReader in(&file);

        //fino alla fine del file
        while(!in.atEnd())
        {
            //se è un tag di apertura
            if(in.readNextStartElement())
            {
                if(in.name() == "UsersList")
                {
                    //se è un tag di apertura
                    while(in.readNextStartElement())
                    {
                        if(in.name() == "User")
                        {
                            //dichiarazioni variabili
                            QString password,name,surname,email,country,city,street;
                            unsigned int age;
                            UserBaseInformations::GenderType gender;
                            //password
                            in.readNextStartElement();
                            password = in.readElementText();
                            //name
                            in.readNextStartElement();
                            name = in.readElementText();
                            //surname
                            in.readNextStartElement();
                            surname = in.readElementText();
                            //email
                            in.readNextStartElement();
                            email = in.readElementText();
                            //age
                            in.readNextStartElement();
                            age = (in.readElementText()).toInt();
                            //gender
                            in.readNextStartElement();
                            gender = static_cast<UserBaseInformations::GenderType>(in.readElementText().toInt());
                            //country
                            in.readNextStartElement();
                            country = in.readElementText();
                            //city
                            in.readNextStartElement();
                            city = in.readElementText();
                            //street
                            in.readNextStartElement();
                            street = in.readElementText();

                            //creo l'oggetto per le amicizie
                            UserContactsNetwork *c = new UserContactsNetwork();

                            //creo l'oggetto per le informazioni
                            UserBaseInformations *i = new UserBaseInformations(name,surname,email,age,gender,country,city,street);

                            //leggo userType e inserisco l'utente nel DB
                           in.readNextStartElement();

                           QString nextElement= in.readElementText();
                           AUser* u;
                           if(nextElement == "FreeUser")
                           {
                               u = new FreeUser(password,c,i);
                           }
                           else if(nextElement == "BusinessUser")
                           {
                               u = new BusinessUser(password,c,i);
                           }
                           else if(nextElement == "ExecutiveUser")
                           {
                               u = new ExecutiveUser(password,c,i);
                           }

                           //se è il tag di apertura della lista di amici
                           in.readNextStartElement();//leggo friendNetwork
                           in.readNextStartElement();//leggo friend
                           while(in.name() == "friend")
                           {
                               QString a = in.readElementText();
                               u->Friends->Add(a);
                               in.readNextStartElement();//leggo friend
                           }


                           //leggo la chiusura di Users
                           in.readNextStartElement();

                           //carico in memoria
                           users.insert(u->Profile->GetEmail(),u);
                        }
                    }
                }
            }
        }

        //chiusura
        file.close();
        return true;
    }
    else
    {
        return false;
    }
}

bool DB::Save()const
{
    return this->Save(this->DBPath);
}

bool DB::Save(const QString& path)const
{
    //controllo se il database è inizializzato
    if(this->DBPath == "")
    {
        return false;
    }
    else
    {
        //apro il file in sola lettura
        QFile file(path);
        file.open(QIODevice::WriteOnly);

        //apro lo streaming di scrittura sul file
        QXmlStreamWriter out(&file);
        out.setAutoFormatting(true);
        out.writeStartDocument();


        out.writeStartElement("UsersList");
        for(QMap<QString,AUser*>::const_iterator it = users.begin();it!=users.end();++it)
        {
            out.writeStartElement("User");
            out.writeTextElement("password",(*it)->GetEncryptedPassword());
            out.writeTextElement("name",(*it)->Profile->GetName());
            out.writeTextElement("surname",(*it)->Profile->GetSurname());
            out.writeTextElement("email",(*it)->Profile->GetEmail());
            out.writeTextElement("age",QString::number((*it)->Profile->GetAge()));//converto age in QString
            out.writeTextElement("gender",QString::number((*it)->Profile->GetGender()));
            out.writeTextElement("country",(*it)->Profile->GetCountry());
            out.writeTextElement("city",(*it)->Profile->GetCity());
            out.writeTextElement("street",(*it)->Profile->GetStreet());
            out.writeTextElement("userType",(*it)->GetSubscriptionType());
            out.writeStartElement("FriendsNetwork");
            UserContactsNetwork* temp = (*it)->Friends;
            for(QList<QString>::const_iterator i = temp->Begin();i!=temp->End();++i)
            {
                out.writeTextElement("friend",*i);
            }
            out.writeEndElement();//fine lista amici
            out.writeEndElement();//fine lista user
        }
        out.writeEndElement();



        //libero le risorse
        out.writeEndDocument();
        file.close();

        //ritorno true
        return true;
    }
}


bool DB::Close()
{
    //controllo se il database è inizializzato
    if(this->DBPath == "")
    {
        return false;
    }
    else
    {
        //elimino dallo heap tutti gli utenti
        this->clearDB();
        return true;
    }
}

bool DB::Restart()
{
    //controllo se il database è inizializzato
    if(this->DBPath == "")
    {
        return false;
    }
    else
    {
        //libero il vettore e dealloco dallo heap gli utenti
        QString temp = DBPath;
        this->clearDB();
        //Ricarico il DB
        this->Load(temp);
        return true;
    }
}

void DB::AddUser(AUser* u)
{
    this->users.insert(u->Profile->GetEmail(),u);
}

bool DB::RemoveUser(AUser* u)
{
    //trovo l'indice dell'elemeno da eliminare
    bool index = this->users.contains(u->Profile->GetEmail());
    //verifico il risultato
    if(index)
    {
        //rimuovo dalla lista degli utenti
        users.remove(u->Profile->GetEmail());

        //dealloco la memoria
        delete u;
        return true;
    }
    else
        return false;
}

AUser* DB::FindUser(const QString& email) const
{
    QMap<QString,AUser*>::const_iterator it = users.find(email);
    if(it == users.end())
        return 0;
    else
        return it.value();
}


bool DB::IsLoad()const
{
    return this->DBPath != "";
}


