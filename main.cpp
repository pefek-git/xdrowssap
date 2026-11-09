#include <QApplication>
#include <QWidget>
#include <QIcon>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QClipboard>
#include <QGuiApplication>
#include <QFile>

#include "generator.h"

int main(int argc, char *argv[]){
  QApplication app(argc, argv);
  
  QFile file("style.qss");

  if (file.open(QFile::ReadOnly)){
    app.setStyleSheet(file.readAll());
  }

  QWidget window;
  window.setWindowTitle("XdrowssaP");
  window.setWindowIcon(QIcon("icon.png"));
  window.resize(350, 250);
  
  auto *layout = new QVBoxLayout(&window);

  auto *title = new QLabel("XdrowssaP Password Generator");
  title->setAlignment(Qt::AlignCenter);

  auto *password = new QLineEdit();
  password->setReadOnly(true);

  auto *length = new QSpinBox();
  length->setRange(8, 64);
  length->setValue(16);

  auto *generate = new QPushButton("Generate");
  auto *copy = new QPushButton("Copy");

  layout->addWidget(title);
  layout->addWidget(password);
  layout->addWidget(length);
  layout->addWidget(generate);
  layout->addWidget(copy);

  QObject::connect(generate, &QPushButton::clicked, [&]() {
      password->setText(
          QString::fromStdString(
            generatePassword(length->value())
            )
          );
      });

  QObject::connect(copy, &QPushButton::clicked, [&](){
      QGuiApplication::clipboard()->setText(password->text());
      });

  window.show();

  return app.exec();
}
