// Copyright (c) 2011-2015 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef UTILITYDIALOG_H
#define UTILITYDIALOG_H

#include <QtWidgets/qdialog.h>
#include <QtCore/qobject.h>
#include "walletmodel.h"

class BitcoinGUI;
class ClientModel;
class SendCoinsRecipient;


namespace Ui {
    class AboutDialog;
    class PaperWalletDialog;
    class CommentDialog;
    class OpennameDialog;
    class DebugDialog;
    class HelpMessageDialog;
}

/** "About" dialog box */
class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog(QWidget *parent);
    ~AboutDialog();

    void setModel(ClientModel *model);

private:
    Ui::AboutDialog *ui;

private slots:
    void on_buttonBox_accepted();
};

/** "Paper Wallet" dialog box */
class PaperWalletDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PaperWalletDialog(QWidget *parent);
    ~PaperWalletDialog();

    void setModel(WalletModel *model);

private:
    Ui::PaperWalletDialog *ui;
    WalletModel *model;
    static const int PAPER_WALLET_READJUST_LIMIT = 20;
    static const int PAPER_WALLET_PAGE_MARGIN = 50;

private slots:
    void on_getNewAddress_clicked();
    void on_printButton_clicked();
};

/** "Comment" dialog box */
class CommentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CommentDialog(QWidget *parent);
    ~CommentDialog();

    void setModel(WalletModel *model);

private:
    Ui::CommentDialog *ui;
    WalletModel *model;
    void processSendCoinsReturn(const WalletModel::SendCoinsReturn &sendCoinsReturn, const QString &msgArg = QString());

private slots:
    void on_insertButton_clicked();
    void on_pushButton_clicked();
    
signals:
    void message(const QString &title, const QString &message, unsigned int style);
};

/** "openname" dialog box */
class OpennameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OpennameDialog(QWidget *parent);
    ~OpennameDialog();

    void setModel(WalletModel *model);

private:
    Ui::OpennameDialog *ui;
    WalletModel *model;
    void processSendCoinsReturn(const WalletModel::SendCoinsReturn &sendCoinsReturn, const QString &msgArg = QString());

private slots:
    void on_insertButton_clicked();
    void on_pushButton_clicked();
    
signals:
    void message(const QString &title, const QString &message, unsigned int style);
};

/** "DebugDialog" dialog box */
class DebugDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DebugDialog(QWidget *parent);
    ~DebugDialog();

    void setModel(WalletModel *model);

private:
    Ui::DebugDialog *ui;
    WalletModel *model;

private slots:
    void on_sxButton_clicked();
    void on_pushButton_clicked();
    
signals:
    void message(const QString &title, const QString &message, unsigned int style);
};

/** "Help message" dialog box */
class HelpMessageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HelpMessageDialog(QWidget *parent);
    ~HelpMessageDialog();

    void printToConsole();
    void showOrPrint();

private:
    Ui::HelpMessageDialog *ui;
    QString header;
    QString coreOptions;
    QString uiOptions;

private slots:
    void on_okButton_accepted();
};


/** "Shutdown" window */
class ShutdownWindow : public QObject
{
    Q_OBJECT

public:
    static void showShutdownWindow(BitcoinGUI *window);
};

#endif // UTILITYDIALOG_H
