#pragma once
#include <QVector>
#include <QMap>
#include <QStringList>
#include "qabstractitemmodel.h"
class ModelEx :	public QAbstractTableModel
{
public:
	explicit ModelEx(QObject *parent = 0);
	virtual ~ModelEx();
	virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
signals:

public slots:

private:
	void populateModel();
private:
	QVector<short> army_;
	QVector<short> weaponType_;
	QMap<short, QString> armyMap_;
	QMap<short, QString> weapoinTypeMap_;
	QStringList weapon_;
	QStringList header_;


};

