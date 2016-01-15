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

#include "linqedinlogin.h"

LinQedInLogin::LinQedInLogin()
{}

LinQedInLogin::~LinQedInLogin()
{}

//---------------------------------
//------------METODI----------------
//----------------------------------
AUser* LinQedInLogin::FindUser(DB* pdb,const QString& email,const QString& password) const
{
    if(pdb->IsLoad())
    {
        //implemento una ricerca nella lista degli utenti
        for(QMap<QString,AUser*>::const_iterator it=pdb->ConstBegin();it!=pdb->ConstEnd();++it)
        {
            if((*it)->Profile->GetEmail() == email && (*it)->GetEncryptedPassword() == (*it)->DoEncryptedPassword(password))
            {
                return *it;
            }
        }
        //altrimenti ritorno il puntatore nullo -> false
        return 0;
    }
    else
    {
        return 0;
    }
}

bool LinQedInLogin::DoAdminLogin() const
{
    DB* database = new DB("db.xml");
    LinQedInAdminController *a = new LinQedInAdminController(new LinQedInAdmin(database));
    a->Show();
    return true;
}

bool LinQedInLogin::DoClientLogin(const QString& email, const QString& password) const
{
    DB* database = new DB("db.xml");
    //ricerca nel DB
    AUser* user = FindUser(database,email,password);
    //verifico il risultato
    if(user == 0)
        return false;
    else
    {
        //do il comando a LinQedInClientController
        LinQedInClientController* a = new LinQedInClientController(new LinQedInClient(database,user),
                                                                   new LinQedInClientView());
        a->Show();
        return true;
    }
}
