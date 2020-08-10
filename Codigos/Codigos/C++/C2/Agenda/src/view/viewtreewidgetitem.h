#ifndef VIEWTREEWIDGETITEM
#define VIEWTREEWIDGETITEM

#include <QTreeWidgetItem>
#include "model/model.h"

class ViewTreeWidgetItem : public QTreeWidgetItem{

private:
    Model *model;

public:
    ViewTreeWidgetItem(Model *model){
        this->model = model;
    }

    Model *getModel(){
        return this->model;
    }

    ~ViewTreeWidgetItem(){
        delete model;
    }
};

#endif // VIEWTREEWIDGETITEM

