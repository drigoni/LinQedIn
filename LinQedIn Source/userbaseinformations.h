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

#ifndef USERBASEINFORMATIONS_H
#define USERBASEINFORMATIONS_H

#include<QString>

class UserBaseInformations
{
public:
    //dichiarazione enumGenderType
    enum GenderType{None=0,Male=1,Female=2};

    //costruttore
    UserBaseInformations(const QString& ="",const QString& ="",const QString& ="",
                         const int& =18,const GenderType& = None,
                         const QString& ="",const QString& ="",const QString& ="");
    virtual ~UserBaseInformations();

    //--------METODI----------
    //Metodi per la lettura
    QString GetName()const;
    QString GetSurname()const;
    QString GetEmail()const;
    int GetAge()const;
    GenderType GetGender()const;
    QString GetCountry()const;
    QString GetCity()const;
    QString GetStreet()const;
    //Metodi per la scrittura
    void SetName(const QString&);
    void SetSurname(const QString&);
    void SetEmail(const QString&);
    void SetAge(const int&);
    void SetGender(const GenderType&);
    void SetCountry(const QString&);
    void SetCity(const QString&);
    void SetStreet(const QString&);

private:
    //campi membro
    QString name;
    QString surname;
    QString email;
    int age;
    GenderType gender;
    QString country;
    QString city;
    QString street;
};

#endif // USERBASEINFORMATIONS_H
