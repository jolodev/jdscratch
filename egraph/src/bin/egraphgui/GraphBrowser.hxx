#ifndef GRAPHBROWSER_HXX
#define GRAPHBROWSER_HXX

#include <QTextBrowser>

class GraphBrowser : public QTextBrowser
{
    Q_OBJECT
public:
    explicit GraphBrowser(QWidget *parent = 0);
    virtual ~GraphBrowser();

signals:

public slots:
    void onAnchorClicked(const QUrl& u);
};

#endif // GRAPHBROWSER_HXX
