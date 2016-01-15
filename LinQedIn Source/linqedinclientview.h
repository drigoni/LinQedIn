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

#ifndef LINQEDINCLIENTVIEW_H
#define LINQEDINCLIENTVIEW_H

#include <auser.h>

#include <QTabWidget>
#include <QWidget>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>

#include <userbaseinfview.h>
#include <usercontactsnetview.h>
#include <userssearchview.h>

class LinQedInClientView:public QWidget
{
    Q_OBJECT
protected:
    //campi dati
    UserBaseInfView* BaseInfTab;//view delle informazioni basi
    UserContactsNetView* NetworkTab;//view della rete delle amicizie
    UsersSearchView* SearchTab;//view della ricerca utenti

    QTabWidget* tabWidget;//oggetto tab
    QVBoxLayout* thisLayout;//per settare il layout

    //metodi
    virtual void initView();

public:
    //costruttore che accetta puntatori ai vari elementi della tab che altrimenti sono creati di default
    LinQedInClientView(UserBaseInfView* =new UserBaseInfView(), UserContactsNetView* = new UserContactsNetView(),
                       UsersSearchView* = new UsersSearchView());
    virtual ~LinQedInClientView();//distruttore

    //metodi
    void ShowBaseInf(const UserBaseInformations*)const;//visualizza il profilo dell'utente
    void ShowAllFriendsNetwork(const QList<const UserBaseInformations*>)const;//visualizza tutti gli amici dell'utente
    void SetUserForm(const QString&)const;//setta la form dell'utente
    void ShowSearchResult(const QList<const UserBaseInformations*>&)const;//visualizza il risultato della ricerca

signals:
    //BaseInfTab
    void BaseInfAsked();//richiede le infomazioni dell'utente
    void BaseInfChanged(UserBaseInformations*);//chiede di salvare le nuovi infomazioni passate come parametro

    //NetworkTab
    void FriendsNetworkAsked();//chiede la rete delle amicizie dell'utente
    void FriendRemoved(const QString&);//chiede di rimuovere un utente

    //SearchTab
    void UserFormAsked();//chiede la form dell'utente
    void Search(UserBaseInformations*);//chiede di effettuare una ricerca
    void FriendAdded(const QString&);//chiede di aggiungere un amico

    //SearchTab && NetworkTab
    void ViewProfile(QString);//chiede di vedere un profilo

};

#endif // LINQEDINCLIENTVIEW_H
