#include "matcontentsmodel.h"

#include <QDebug>

#include <matio.h>

MATContentsModel::MATContentsModel(QObject *parent) :
    QAbstractTableModel(parent)
{
}

void MATContentsModel::parseMAT(const QString &filename)
{
    mat_t* m = Mat_Open(filename.toAscii(), MAT_ACC_RDONLY);


    Mat_Close(m);
}

int MATContentsModel::rowCount(const QModelIndex &parent) const
{

}

int MATContentsModel::columnCount(const QModelIndex &parent) const
{

}

QVariant MATContentsModel::data(const QModelIndex &index, int role) const
{

}

QVariant MATContentsModel::headerData(int section, Qt::Orientation orientation, int role) const
{

}
