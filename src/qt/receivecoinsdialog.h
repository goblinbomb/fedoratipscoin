// Copyright (c) 2011-2014 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef RECEIVECOINSDIALOG_H
#define RECEIVECOINSDIALOG_H

#include <QtWidgets/qdialog.h>
#include <QtWidgets/qheaderview.h>
#include <QtCore/qitemselectionmodel.h>
#include <QtGui/QKeyEvent>
#include <QtWidgets/qmenu.h>
#include <QtCore/qpoint.h>
#include <QtCore/qvariant.h>

#include "guiutil.h"

namespace Ui {
    class ReceiveCoinsDialog;
}
class WalletModel;
class OptionsModel;

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

/** Dialog for requesting payment of bitcoins */
class ReceiveCoinsDialog : public QDialog
{
    Q_OBJECT

public:
    enum ColumnWidths {
        DATE_COLUMN_WIDTH = 130,
        LABEL_COLUMN_WIDTH = 120,
        AMOUNT_MINIMUM_COLUMN_WIDTH = 160,
        MINIMUM_COLUMN_WIDTH = 130
    };

    explicit ReceiveCoinsDialog(QWidget *parent = 0);
    ~ReceiveCoinsDialog();

    void setModel(WalletModel *model);

public slots:
    void clear();
    void reject();
    void accept();

protected:
    virtual void keyPressEvent(QKeyEvent *event);

private:
    Ui::ReceiveCoinsDialog *ui;
    GUIUtil::TableViewLastColumnResizingFixer *columnResizingFixer;
    WalletModel *model;
    QMenu *contextMenu;
    void copyColumnToClipboard(int column);
    virtual void resizeEvent(QResizeEvent* event);

private slots:
    void on_receiveButton_clicked();
    void on_showRequestButton_clicked();
    void on_removeRequestButton_clicked();
    void on_recentRequestsView_doubleClicked(const QModelIndex &index);
    void on_recentRequestsView_selectionChanged(const QItemSelection &, const QItemSelection &);
    void updateDisplayUnit();
    void showMenu(const QPoint &);
    void copyLabel();
    void copyMessage();
    void copyAmount();
};

#endif // RECEIVECOINSDIALOG_H
