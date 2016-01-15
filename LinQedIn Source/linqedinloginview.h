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

#ifndef LINQEDINLOGINVIEW_H
#define LINQEDINLOGINVIEW_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QFormLayout>
#include <QPushButton>
#include <QVBoxLayout>

class LinQedInLoginView:public QWidget
{
    Q_OBJECT
protected:
    QLabel *loginLbl;
    QLabel *messageLbl;
    QLineEdit *emailText;
    QLineEdit *passwordText;
    QHBoxLayout *confirmBox;
    QFormLayout *form;
    QVBoxLayout *screen;
    QPushButton *confermaBtn;
    QPushButton *adminLoginBtn;

    virtual void initView();//inizzializza la view

public:
    LinQedInLoginView();
    virtual ~LinQedInLoginView();//distruttore

    //metodo
    virtual void SetMessage(const QString& ="",const QColor& = QColor(Qt::black));//setta il messaggio

signals:
    void doUserLogin(const QString&,const QString&);//chiede di effettuare il login utente
    void doAdminLogin();//chiede di effettuare il login amministratore

public slots:
    void loginClicked(); //verifica se i dati sono stati inseriti ed emette il segnale di login
};

#endif // LINQEDINLOGINVIEW_H
