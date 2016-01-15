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

#include "userbaseinformations.h"

//-------------------------------------------------------------------------------------
//CLASSE UserBaseInformations
//-------------------------------------------------------------------------------------
UserBaseInformations::UserBaseInformations(const QString& n, const QString &s,const QString &e,const int& a,
                            const GenderType& g,const QString& c,const QString &cit,const QString& stre)
    :name(n),surname(s),email(e),age(a),gender(g),country(c),city(cit),street(stre)
{}

UserBaseInformations::~UserBaseInformations()
{}

//metodi per la lettura
QString UserBaseInformations::GetName()const
{
    return name;
}
QString UserBaseInformations::GetSurname()const
{
    return surname;
}
QString UserBaseInformations::GetEmail()const
{
    return email;
}
int UserBaseInformations::GetAge()const
{
    return age;
}
UserBaseInformations::GenderType UserBaseInformations::GetGender()const
{
    return gender;
}
QString UserBaseInformations::GetCountry()const
{
    return country;
}
QString UserBaseInformations::GetCity()const
{
    return city;
}
QString UserBaseInformations::GetStreet()const
{
    return street;
}
//metodi per la scrittura
void UserBaseInformations::SetName(const QString &n)
{
    name = n;
}
void UserBaseInformations::SetSurname(const QString &s)
{
    surname= s;
}
void UserBaseInformations::SetEmail(const QString &e)
{
    email=e;
}
void UserBaseInformations::SetAge(const int &a)
{
    age= a;
}
void UserBaseInformations::SetGender(const GenderType &g)
{
    gender=g;
}
void UserBaseInformations::SetCountry(const QString &c)
{
    country=c;
}
void UserBaseInformations::SetCity(const QString &c)
{
    city=c;
}
void UserBaseInformations::SetStreet(const QString &s)
{
    street=s;
}

