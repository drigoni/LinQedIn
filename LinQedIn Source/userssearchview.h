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

#ifndef USERSSEARCHVIEW_H
#define USERSSEARCHVIEW_H

#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QTableWidget>
#include <QHeaderView>
#include <QGridLayout>
#include <QFormLayout>
#include <QComboBox>

#include<userbaseinformations.h>

class UsersSearchView:public QWidget
{
    Q_OBJECT
protected:
    //parte informazioni base
    QLabel* MessageLbl;
    QVBoxLayout* VBox;
    QFormLayout* Form;
    QTableWidget* ResultTable;
    QPushButton* SearchBtn;
    QLineEdit* nameText;
    QLineEdit* surnameText;
    QLineEdit* emailText;
    QLineEdit* ageText;
    QComboBox* genderCB;
    QLineEdit* countryText;
    QLineEdit* cityText;
    QLineEdit* streetText;
    QPushButton* addFriend;
    QGridLayout* gridLayout;
    QPushButton* viewProfileBtn;
    QVBoxLayout* VBoxBtn;


    virtual void initView();//inizzializza la view
public:
    UsersSearchView();

    //metodi
    virtual void SetMessage(const QString& ="",const QColor& = QColor(Qt::black)); //Setta il messaggio della label dei risultati
    virtual void SetUserForm(const QString&);//setta la form a seconda dell'utente
    virtual void ShowSearchResult(const QList<const UserBaseInformations*>&);//mostra i risultati della ricerca

private slots:
    void SearchBtnClicked();//verifica i dati inseriti e emette il segnale per la ricerca
    void AddFriendClicked();//emette il segnale per la ricerca
    void ViewProfileClicked();// emette il segnale per la visione di un profilo

signals:
    void UserFormAsked();//chiede la form dell'utente
    void Search(UserBaseInformations*);//chiede di cercare un utente
    void AddFriend(QString);//chiede di aggiungere un utente dato il parametro email

    void ViewProfile(QString);//richiede di vedere il profilo data una email
};

#endif // USERSSEARCHVIEW_H
