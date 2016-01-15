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

#include <linqedinadmin.h>


LinQedInAdmin::LinQedInAdmin(DB *pdb):db(pdb)
{}

LinQedInAdmin::~LinQedInAdmin()
{}


//---------------------------------
//------------METODI----------------
//----------------------------------
bool LinQedInAdmin::IsDBLoad()const
{
    return this->db->IsLoad();
}

bool LinQedInAdmin::LoadDB(const QString& path) const
{
    return this->db->Load(path);
}

bool LinQedInAdmin::SaveDB()const
{
    return this->db->Save();
}

bool LinQedInAdmin::SaveDB(const QString& path) const
{
    return this->db->Save(path);
}

bool LinQedInAdmin::CloseDB() const
{
    return this->db->Close();
}

bool LinQedInAdmin::RestartDB()const
{
    return this->db->Restart();
}

AUser* LinQedInAdmin::FindUser(const QString& email) const
{
    return db->FindUser(email);
}

QVector<AUser*> LinQedInAdmin::FindUser(const QString& name, const QString& surname,const QString& email) const
{
    QVector<AUser*> result;
    if(name=="")
    {
       if(surname == "")
       {
           if(email == "")
           {
               //nessun parametro corretto e dunque restituisco tutti gli utenti
               for(QMap<QString,AUser*>::const_iterator it=db->ConstBegin();it!=db->ConstEnd();++it)
               {
                    result.push_back(*it);
               }
           }
           else
           {
               //ricerca per email
               for(QMap<QString,AUser*>::const_iterator it=db->ConstBegin();it!=db->ConstEnd();++it)
               {
                   if((*it)->Profile->GetEmail() == email)
                       result.push_back(*it);
               }
           }
       }
       else
       {
           if(email == "")
           {
               //ricerca per cognome
               for(QMap<QString,AUser*>::const_iterator it=db->ConstBegin();it!=db->ConstEnd();++it)
               {
                   if((*it)->Profile->GetSurname() == surname)
                       result.push_back(*it);
               }
           }
           else
           {
               //ricerca per cognome e email
               for(QMap<QString,AUser*>::const_iterator it=db->ConstBegin();it!=db->ConstEnd();++it)
               {
                   if((*it)->Profile->GetEmail() == email && (*it)->Profile->GetSurname() == surname)
                       result.push_back(*it);
               }
           }
       }
   }
   else
   {
       if(surname == "")
       {
           if(email == "")
           {
               //ricerca per nome
               for(QMap<QString,AUser*>::const_iterator it=db->ConstBegin();it!=db->ConstEnd();++it)
               {
                   if((*it)->Profile->GetName() == name)
                       result.push_back(*it);
               }
           }
           else
           {
               //ricerca per nome ed email
               for(QMap<QString,AUser*>::const_iterator it=db->ConstBegin();it!=db->ConstEnd();++it)
               {
                   if((*it)->Profile->GetName() == name && (*it)->Profile->GetEmail() == email)
                       result.push_back(*it);
               }
           }
       }
       else
       {
           if(email == "")
           {
               //ricerca per nome e cognome
               for(QMap<QString,AUser*>::const_iterator it=db->ConstBegin();it!=db->ConstEnd();++it)
               {
                   if((*it)->Profile->GetName() == name && (*it)->Profile->GetSurname() == surname )
                       result.push_back(*it);
               }
           }
           else
           {
               //ricerca per nome, cognome ed email
               for(QMap<QString,AUser*>::const_iterator it=db->ConstBegin();it!=db->ConstEnd();++it)
               {
                   if((*it)->Profile->GetName() == name && (*it)->Profile->GetSurname() == surname && (*it)->Profile->GetEmail() == email )
                       result.push_back(*it);
               }
           }
       }
   }

   //ritorno il vettore risultante
   return result;
}


//metodi di aggiunta utente
void LinQedInAdmin::AddFreeUser(const QString& name, const QString& surname, const QString& email, const QString& password) const
{
    //creazione utente
    FreeUser* newUser = new FreeUser(name,surname,email,password);
    //aggiunta del nuovo utente al database
    this->db->AddUser(newUser);

}

void LinQedInAdmin::AddBusinessUser(const QString& name, const QString& surname, const QString& email, const QString& password) const
{
    //creazione utente
    BusinessUser* newUser = new BusinessUser(name,surname,email,password);
    //aggiunta del nuovo utente al database
    this->db->AddUser(newUser);

}

void LinQedInAdmin::AddExecutiveUser(const QString& name, const QString& surname, const QString& email, const QString& password) const
{
    //creazione utente
    ExecutiveUser* newUser = new ExecutiveUser(name,surname,email,password);
    //aggiunta del nuovo utente al database
    this->db->AddUser(newUser);

}

bool LinQedInAdmin::RemoveUser(const QString& email) const
{
    return this->db->RemoveUser(db->FindUser(email));
}

void LinQedInAdmin::ChangeSubscriptionType(AUser* user, const QString& newSubscriptionType) const
{
    //ricreo l'utente a seconda del nuovo tipo e ci copio le informaioni
    if(newSubscriptionType == "FreeUser")
    {
        UserContactsNetwork* n = new UserContactsNetwork(*user->Friends);
        UserBaseInformations* p = new UserBaseInformations(*user->Profile);

        //creo il nuovo utente con i campi di quello vecchio
        FreeUser* b = new FreeUser(user->GetEncryptedPassword(),n,p);
        //rimuovo nel DB l'utente vecchio e elimino dallo heap
        this->db->RemoveUser(user);
        //aggiungo nel DB il nuovo utente
        this->db->AddUser(b);
    }
    else if(newSubscriptionType == "BusinessUser")
    {
        UserContactsNetwork* n = new UserContactsNetwork(*user->Friends);
        UserBaseInformations* p = new UserBaseInformations(*user->Profile);

        //creo il nuovo utente con i campi di quello vecchio
        BusinessUser* b = new BusinessUser(user->GetEncryptedPassword(),n,p);
        //rimuovo nel DB l'utente vecchio e elimino dallo heap
        this->db->RemoveUser(user);
        //aggiungo nel DB il nuovo utente
        this->db->AddUser(b);
    }
    else if(newSubscriptionType == "ExecutiveUser")
    {
        UserContactsNetwork* n = new UserContactsNetwork(*user->Friends);
        UserBaseInformations* p = new UserBaseInformations(*user->Profile);

        //creo il nuovo utente con i campi di quello vecchio
        ExecutiveUser* b = new ExecutiveUser(user->GetEncryptedPassword(),n,p);
        //rimuovo nel DB l'utente vecchio e elimino dallo heap
        this->db->RemoveUser(user);
        //aggiungo nel DB il nuovo utente
        this->db->AddUser(b);
    }
}



