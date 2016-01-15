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

#ifndef USERCONTACTSNETVIEW_H
#define USERCONTACTSNETVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QTableWidget>
#include <QHeaderView>
#include <QGridLayout>

#include <auser.h>

class UserContactsNetView: public QWidget
{
    Q_OBJECT
protected:
    //parte informazioni base
    QLabel* MessageLbl;
    QVBoxLayout* VBox;
    QTableWidget* FriendTable;
    QGridLayout* GridBox;
    QVBoxLayout* VBoxBtn;
    QPushButton* RemoveBtn;
    QPushButton* RefreshBtn;
    QPushButton* ViewUserProfileBtn;


    virtual void initView();

public:
    UserContactsNetView();
    virtual ~UserContactsNetView();

    //metodi
    virtual void SetMessage(const QString& ="",const QColor& = QColor(Qt::black)); //Setta il messaggio della label dei risultati
    void ShowAllFriendsNetwork(const QList<const UserBaseInformations *>);//Inserisce tutti i dati nella tabella

private slots:
    void RemoveClick();//rimuove l'utente dalla tabella e segnala RemoveFriendClicked
    void ViewProfileClicked();

signals:
    void RemoveFriendClicked(const QString&);//segnala di rimuovere un utente
    void FriendsNetworkAsked();//richiede la rete di amicizia dell'utente
    void ViewProfile(QString);//richiede di vedere il profilo data una email

};

#endif // USERCONTACTSNETVIEW_H
