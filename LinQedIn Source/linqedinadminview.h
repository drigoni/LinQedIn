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

#ifndef LINQEDINADMINVIEW_H
#define LINQEDINADMINVIEW_H

//inclusione di WIDGET
#include <QWidget>
#include <QGroupBox>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QTableWidget>
#include <QVector>
#include <QHeaderView>

//inclusione di ALTRO
#include <auser.h>

class LinQedInAdminView:public QWidget
{
    Q_OBJECT
protected:
    //campi dati
    QLabel* adminLbl;
    QLabel* messageLbl;

    //GroupBox DB
    QGroupBox* dbGB;
    QComboBox* dbOperationsCB;
    QLineEdit* dbPathText;
    QPushButton* dbProceedBtn;
    QHBoxLayout* dbOperationsLayout;

    //GroupBox AddUser
    QGroupBox* addUsersGB;
    QLineEdit* addUserNameText;
    QLineEdit* addUserUsernameText;
    QLineEdit* addUserEmailText;
    QLineEdit* addUserPassowrdText;
    QLineEdit* addUserPassowrdConfirmText;
    QPushButton* addUserProceedBtn;
    QFormLayout* addUserFormLayout;
    QComboBox* addUserTypeCB;

    //GroupBox FindUser
    QGroupBox* findGB;
    QLineEdit* findNameText;
    QLineEdit* findSurnameText;
    QLineEdit* findEmailText;
    QPushButton* findProceedBtn;
    QTableWidget* findResultTbl;
    QPushButton* removeUserBtn;
    QPushButton* changeSubTypeBtn;
    QComboBox* subscriptyonTypeCB;
    QFormLayout* findFormLayout;
    QHBoxLayout* findHLayout;
    QVBoxLayout* findVLayout;
    QVBoxLayout* findVUOLayout;
    QHBoxLayout* findHVOLayout;

    //Layout Generale
    QGridLayout* gridLayout;
    QVBoxLayout* screenLayout;
    QGroupBox* changeUsersGB;


    //metodi
    virtual void initView(); //inizializzazione della grafica

public:
    LinQedInAdminView();
    virtual ~LinQedInAdminView();

    //metodi
    virtual void SetMessage(const QString& ="",const QColor& = QColor(Qt::black)); //Setta il messaggio della label dei risultati
    void ShowUsersResult(QVector<AUser*>,bool);//Aggiunge i dati ricevuti nella tabella


private slots:
    virtual void dbFindUsers();//emette il segnale con i relativi dati per la ricerca dell'utente
    virtual void dbDoOperation();//emette il segnale con i relativi dati per effettuare cambiamenti nel DB
    virtual void dbAddNewUser();//emette il segnale con i relativi dati per aggiungere un utente
    virtual void dbRemoveUser();//emette il segnale con i relativi dati per rimuovere un utente
    virtual void dbChangeUserSub();//emette il segnale con i relativi dati per cambiare il tipo dell'utente
    virtual void currentDBOChanged(const QString&);//attiva o meno la QLineEdit per l'inserimento della path


signals:
    void dbFindUsers(const QString&,const QString&,const QString&);//segnale ricerca utente. nome-cognome-email
    void dbDoOperation(const QString&,const QString&);//segnale operaione DB. operation-path
    void dbAddNewUser(const QString&,const QString&,const QString&,const QString&,const QString&,const QString&);//segnale aggiunta utente. nome-cognome-email-password-confirmedPassword-tipo
    void dbRemoveUser(const QString&);//segnale rimoione utente. ID
    void dbChangeUserSub(const QString&, const QString&);//segnale cambio tipo utente. ID-nuovoTipo

};


#endif // LINQEDINADMINVIEW_H
