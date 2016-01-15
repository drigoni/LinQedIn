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

#include "userbaseinfview.h"

UserBaseInfView::UserBaseInfView()
{
    initView();
}
UserBaseInfView::UserBaseInfView(UserBaseInformations* inf)
{
    initView();
    this->EditBtn->setVisible(false);
    this->BackBtn->setVisible(false);

    //setto i valori
    this->ShowBaseInf(inf);
}

UserBaseInfView::~UserBaseInfView()
{}



//------------------------------------------
//------------METODI PROTETTI----------------
//-----------------------------------------
void UserBaseInfView::initView()
{
    VBox = new QVBoxLayout();
    Form = new QFormLayout();
    NameText = new QLineEdit(this);
    SurnameText = new QLineEdit(this);
    EmailText = new QLineEdit(this);
    AgeText = new QLineEdit(this);
    GenderCB = new QComboBox(this);
    CountryText = new QLineEdit(this);
    CityText = new QLineEdit(this);
    StreetText = new QLineEdit(this);
    EditBtn = new QPushButton(this);
    BackBtn = new QPushButton(this);
    MessageLbl = new QLabel(this);
    TitleLbl = new QLabel(this);
    HBox = new QHBoxLayout();

    //config NameText
    this->NameText->setEnabled(false);
    //config SurnameText
    this->SurnameText->setEnabled(false);
    //config EmailText
    this->EmailText->setEnabled(false);
    //config AgeText
    this->AgeText->setEnabled(false);
    //config GenderCB
    this->GenderCB->addItem(tr("Maschio"),1);
    this->GenderCB->addItem(tr("Femmina"),2);
    this->GenderCB->setEnabled(false);
    //config CountryText
    this->CountryText->setEnabled(false);
    //config CotyText
    this->CityText->setEnabled(false);
    //config StreetText
    this->StreetText->setEnabled(false);
    //config EditBtn
    this->EditBtn->setText(tr("Modifica"));
    //config BackBtn
    this->BackBtn->setText(tr("Annulla"));
    this->BackBtn->setEnabled(false);

    //config HBox
    this->HBox->addWidget(BackBtn,0,Qt::AlignLeft);
    this->HBox->addWidget(EditBtn,0,Qt::AlignRight);

    //config Form
    this->Form->addRow(tr("Nome"),this->NameText);
    this->Form->addRow(tr("Cognome"),this->SurnameText);
    this->Form->addRow(tr("Email"),this->EmailText);
    this->Form->addRow(tr("Età"),this->AgeText);
    this->Form->addRow(tr("Sesso"),this->GenderCB);
    this->Form->addRow(tr("Stato"),this->CountryText);
    this->Form->addRow(tr("Città"),this->CityText);
    this->Form->addRow(tr("Via"),this->StreetText);
    this->Form->addItem(HBox);


    //config VBox
    this->VBox->addWidget(this->TitleLbl,0,Qt::AlignCenter);
    this->VBox->addWidget(this->MessageLbl,0,Qt::AlignCenter);
    this->VBox->addLayout(this->Form,Qt::AlignTop);

    //config Widget
    this->setLayout(this->VBox);

    //config connect
    connect(this->EditBtn,SIGNAL(clicked()),this,SLOT(EditBtnClick()));
    connect(this->BackBtn,SIGNAL(clicked()),this,SLOT(BackBtnClick()));
}


//---------------------------------
//------------METODI----------------
//----------------------------------
void UserBaseInfView::SetMessage(const QString &message, const QColor& c)
{
    QPalette pal = MessageLbl->palette(); //setto un nuovo colore
    pal.setColor(QPalette::WindowText,c);
    MessageLbl->setPalette(pal); //cambio palette
    MessageLbl->setText(message);
}

void UserBaseInfView::ShowBaseInf(const UserBaseInformations *p)
{
    this->NameText->setText(p->GetName());
    this->SurnameText->setText(p->GetSurname());
    this->EmailText->setText(p->GetEmail());
    this->AgeText->setText(QString::number(p->GetAge()));
    this->GenderCB->setCurrentIndex(p->GetGender()-1);//meno uno in quanto il valore none non è presente
    this->CountryText->setText(p->GetCountry());
    this->CityText->setText(p->GetCity());
    this->StreetText->setText(p->GetStreet());

    //config MessageLbl
    this->TitleLbl->setText(p->GetName() + " " + p->GetSurname());
}


//slots
void UserBaseInfView::EditBtnClick()
{
    //verifico il testo del messaggio per eseguire i comandi
    if(this->EditBtn->text() == "Modifica")
    {
        //cambio testo messageLbl
        this->SetMessage("Modifica dei dati in corso.");

        //attivo tutti i QLineEdit
        this->NameText->setEnabled(true);
        this->SurnameText->setEnabled(true);
        this->EmailText->setEnabled(false);
        this->AgeText->setEnabled(true);
        this->GenderCB->setEnabled(true);
        this->CountryText->setEnabled(true);
        this->CityText->setEnabled(true);
        this->StreetText->setEnabled(true);
        this->EditBtn->setText(tr("Salva"));
        this->BackBtn->setEnabled(true);
    }
    else if (this->EditBtn->text() == "Salva")
    {
        //cambio testo messageLbl
        this->SetMessage("Modifica dei dati completata con successo.",QColor(Qt::green));

        //disattivo tutti i QLineEdit
        this->NameText->setEnabled(false);
        this->SurnameText->setEnabled(false);
        this->EmailText->setEnabled(false);
        this->AgeText->setEnabled(false);
        this->GenderCB->setEnabled(false);
        this->CountryText->setEnabled(false);
        this->CityText->setEnabled(false);
        this->StreetText->setEnabled(false);
        this->EditBtn->setText(tr("Modifica"));
        this->BackBtn->setEnabled(false);

        //salvo le modifiche
        UserBaseInformations* newBaseInf = new UserBaseInformations(
                    NameText->text(),
                    SurnameText->text(),
                    EmailText->text(),
                    (AgeText->text()).toInt(),
                    static_cast<UserBaseInformations::GenderType>(GenderCB->currentIndex()+1),
                    CountryText->text(),
                    CityText->text(),
                    StreetText->text());

        emit this->SaveBtnClicked(newBaseInf);
    }
}

void UserBaseInfView::BackBtnClick()
{
    //cambio testo messageLbl
    this->SetMessage("Modifica dei dati annullata.");

    //disattivo tutti i QLineEdit
    this->NameText->setEnabled(false);
    this->SurnameText->setEnabled(false);
    this->EmailText->setEnabled(false);
    this->AgeText->setEnabled(false);
    this->GenderCB->setEnabled(false);
    this->CountryText->setEnabled(false);
    this->CityText->setEnabled(false);
    this->StreetText->setEnabled(false);
    this->EditBtn->setText(tr("Modifica"));
    this->BackBtn->setEnabled(false);
}


