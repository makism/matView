#ifndef MATCONTENTSMODEL_H
#define MATCONTENTSMODEL_H

#include <QAbstractTableModel>

class MATContentsModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit MATContentsModel(QObject *parent = 0);

    void parseMAT(const QString& filename);

signals:

public slots:


    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
};

#endif // MATCONTENTSMODEL_H
