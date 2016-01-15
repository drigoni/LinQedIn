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

#include "businessuser.h"

BusinessUser::BusinessUser(const QString &name, const QString &surname, const QString &email, const QString &password)
    :AUser(name,surname,email,password)
{
}

BusinessUser::BusinessUser( const QString &pass,UserContactsNetwork* contacts, UserBaseInformations *prof)
                           :AUser(pass,contacts,prof)
{}



//---------------------------------
//------------METODI----------------
//----------------------------------
QString BusinessUser::GetSubscriptionType()const
{
    return "BusinessUser";
}

QList<const UserBaseInformations*> BusinessUser::Search(QMap<QString,AUser*>::const_iterator begin,QMap<QString,AUser*>::const_iterator end, const UserBaseInformations &inf) const
{
    //prima parte di codice
    QSet<const UserBaseInformations*> nameSet;
    QSet<const UserBaseInformations*> emailSet;
    QSet<const UserBaseInformations*> surnameSet;
    QSet<const UserBaseInformations*> ageSet;
    QSet<const UserBaseInformations*> genderSet;
    bool set = false;
    QSet<const UserBaseInformations*> resultSet;

    if(inf.GetName() != "")
    {

        for(QMap<QString,AUser*>::const_iterator it = begin;it != end ;it++)
        {
            if((*it)->Profile->GetName() == inf.GetName())
                nameSet.insert((*it)->Profile);
        }

        if(!set)
        {
            set = true;
            resultSet = nameSet;
        }
    }

    if(inf.GetEmail() != "")
    {
        for(QMap<QString,AUser*>::const_iterator it = begin;it != end ;it++)
        {
            if((*it)->Profile->GetEmail() == inf.GetEmail())
                emailSet.insert((*it)->Profile);
        }

        if(!set)
        {
            set = true;
            resultSet = emailSet;
        }
    }

    if(inf.GetSurname() != "")
    {
        for(QMap<QString,AUser*>::const_iterator it = begin;it != end ;it++)
        {
            if((*it)->Profile->GetSurname() == inf.GetSurname())
                surnameSet.insert((*it)->Profile);
        }
        if(!set)
        {
            set = true;
            resultSet = surnameSet;
        }
    }

    if(inf.GetAge() != 0)
    {
        for(QMap<QString,AUser*>::const_iterator it = begin;it != end ;it++)
        {
            if((*it)->Profile->GetAge() == inf.GetAge())
                ageSet.insert((*it)->Profile);
        }
        if(!set)
        {
            set = true;
            resultSet = ageSet;
        }
    }

    if(inf.GetGender() != 0)
    {
        for(QMap<QString,AUser*>::const_iterator it = begin;it != end ;it++)
        {
            if((*it)->Profile->GetGender() == inf.GetGender())
                genderSet.insert((*it)->Profile);
        }

        if(!set)
        {
            set = true;
            resultSet = genderSet;
        }
    }

    if(inf.GetName()!="")
        resultSet.intersect(nameSet);
    if(inf.GetEmail()!= "")
        resultSet.intersect(emailSet);
    if(inf.GetSurname()!="")
        resultSet.intersect(surnameSet);
    if(inf.GetAge()!= 0)
        resultSet.intersect(ageSet);
    if(inf.GetGender() != 0)
        resultSet.intersect(genderSet);

    //rimuovo se presente me stesso
    resultSet.remove(this->Profile);
    return QList<const UserBaseInformations*>::fromSet(resultSet);
}
