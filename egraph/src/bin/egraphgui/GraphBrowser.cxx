#include "GraphBrowser.hxx"

#include <QDebug>
#include <QUrl>

GraphBrowser::GraphBrowser(QWidget *parent) :
    QTextBrowser(parent)
{
    setOpenLinks(false);
    connect(this, &QTextBrowser::anchorClicked, this, &GraphBrowser::onAnchorClicked);
}

GraphBrowser::~GraphBrowser()
{

}

void GraphBrowser::onAnchorClicked(const QUrl &u)
{
    qDebug() << "clicked: " << u.toString();
    qDebug() << "scheme: " << u.scheme();
    qDebug() << "host: " << u.host();
    qDebug() << "query: " << u.query();
}
