#include "ModelEx.h"


ModelEx::ModelEx(QObject * parent)
{
	armyMap_[1] = QStringLiteral("�վ�");
	armyMap_[2] = QStringLiteral("����");
	armyMap_[3] = QStringLiteral("½��");
	armyMap_[4] = QStringLiteral("����½ս��");
	weapoinTypeMap_[1] = QStringLiteral("��ը��");
	weapoinTypeMap_[2] = QStringLiteral("ս����");
	weapoinTypeMap_[3] = QStringLiteral("����ĸ��");
	weapoinTypeMap_[4] = QStringLiteral("����");
	weapoinTypeMap_[5] = QStringLiteral("ֱ����");
	weapoinTypeMap_[6] = QStringLiteral("̹��");
	weapoinTypeMap_[7] = QStringLiteral("���ܹ�����");
	weapoinTypeMap_[8] = QStringLiteral("����ս��");
	populateModel();
}

ModelEx::~ModelEx()
{
}

int ModelEx::rowCount(const QModelIndex & parent) const
{
	return army_.size();
}

int ModelEx::columnCount(const QModelIndex & parent) const
{
	return 3;
}

QVariant ModelEx::data(const QModelIndex & index, int role) const
{
	if (!index.isValid())
		return QVariant();
	if (role == Qt::DisplayRole)
	{
		switch (index.column())
		{
		case 0:
			return armyMap_[army_[index.row()]];
			break;
		case 1:
			return weapoinTypeMap_[weaponType_[index.row()]];
			break;
		case 2:
			return weapon_[index.row()];
			break;
		default:
			return QVariant();
			break;
		}
	}
	return QVariant();
}

QVariant ModelEx::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
		return header_[section];
	return QAbstractTableModel::headerData(section, orientation, role);
}

void ModelEx::populateModel()
{
	header_ << QStringLiteral("����") << QStringLiteral("����") << QStringLiteral("����");
	army_ << 1 << 2 << 3 << 4 << 2 << 4 << 3 << 1;
	weaponType_ << 1 << 3 << 5 << 7 << 4 << 8 << 6 << 2;
	weapon_ << QStringLiteral("B-2") << QStringLiteral("�����ȼ�") << QStringLiteral("������") 
		<< QStringLiteral("�Ʒ伶") << QStringLiteral("�������˼�") << QStringLiteral("AAAV") << QStringLiteral("M1A1") << QStringLiteral("F-22");
}