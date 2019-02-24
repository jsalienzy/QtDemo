#include "ModelEx.h"


ModelEx::ModelEx(QObject * parent)
{
	armyMap_[1] = QStringLiteral("空军");
	armyMap_[2] = QStringLiteral("海军");
	armyMap_[3] = QStringLiteral("陆军");
	armyMap_[4] = QStringLiteral("海军陆战队");
	weapoinTypeMap_[1] = QStringLiteral("轰炸机");
	weapoinTypeMap_[2] = QStringLiteral("战斗机");
	weapoinTypeMap_[3] = QStringLiteral("航空母舰");
	weapoinTypeMap_[4] = QStringLiteral("驱逐舰");
	weapoinTypeMap_[5] = QStringLiteral("直升机");
	weapoinTypeMap_[6] = QStringLiteral("坦克");
	weapoinTypeMap_[7] = QStringLiteral("两栖攻击舰");
	weapoinTypeMap_[8] = QStringLiteral("两栖战车");
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
	header_ << QStringLiteral("军种") << QStringLiteral("种类") << QStringLiteral("武器");
	army_ << 1 << 2 << 3 << 4 << 2 << 4 << 3 << 1;
	weaponType_ << 1 << 3 << 5 << 7 << 4 << 8 << 6 << 2;
	weapon_ << QStringLiteral("B-2") << QStringLiteral("尼米兹级") << QStringLiteral("阿帕奇") 
		<< QStringLiteral("黄蜂级") << QStringLiteral("阿利伯克级") << QStringLiteral("AAAV") << QStringLiteral("M1A1") << QStringLiteral("F-22");
}