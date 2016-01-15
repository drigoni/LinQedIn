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

#ifndef USERBASEINFVIEW_H
#define USERBASEINFVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>

#include<auser.h>

class UserBaseInfView:public QWidget
{
    Q_OBJECT
protected:
    //parte informazioni base
    QLabel* TitleLbl;
    QLabel* MessageLbl;
    QVBoxLayout* VBox;
    QFormLayout* Form;
    QLineEdit* NameText;
    QLineEdit* SurnameText;
    QLineEdit* EmailText;
    QLineEdit* AgeText;
    QComboBox* GenderCB;
    QLineEdit* CountryText;
    QLineEdit* CityText;
    QLineEdit* StreetText;
    QPushButton* EditBtn;
    QPushButton* BackBtn;
    QHBoxLayout* HBox;


    virtual void initView();//inizzializza la grafica
public:
    UserBaseInfView();
    UserBaseInfView(UserBaseInformations*);
    virtual ~UserBaseInfView();//distruttore

    //metodi
    virtual void SetMessage(const QString& ="",const QColor& = QColor(Qt::black)); //Setta il messaggio della label dei risultati
    virtual void ShowBaseInf(const UserBaseInformations*);//mostra le informazioni del profilo passato come parametro

private slots:
    void EditBtnClick();//verifica se deve salvare o modificare i campi
    void BackBtnClick();//disattiva i campi

signals:
    void SaveBtnClicked(UserBaseInformations*);//chiede di salvare il nuovo profilo
    void BaseInfAsked();//chiede il profilo dell'utente
};

#endif // USERBASEINFVIEW_H
