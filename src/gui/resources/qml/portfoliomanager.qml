import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
  width: 800
  height: 600

  ColumnLayout {
    anchors.fill: parent
    spacing: 0

    // upper
    Rectangle {
      Layout.fillWidth: true
      Layout.preferredHeight: parent.height * 0.2
      color: "#130e2b"
      border.color: "black"

      Column {
        anchors.centerIn: parent
        spacing: 10

        Text {
          color: "white"
          font.pointSize: 20
          text: "Total value: " + controller.total_value
        }

        Button {
          anchors.horizontalCenter: parent.horizontalCenter
          text: "Add portfolio"
          onClicked: add_portfolio_dialog.open()
        }
      }

      Dialog {
        id: add_portfolio_dialog
        anchors.centerIn: parent
        modal: true
        standardButtons: Dialog.Ok | Dialog.Cancel

        contentItem: ColumnLayout {
          spacing: 20
          width: parent.width

          Label {
            text: "Enter portfolio name:"
            Layout.alignment: Qt.AlignLeft
          }

          TextField {
            id: portfolio_name_field
            Layout.fillWidth: true
            focus: true

            Component.onCompleted: {
              add_portfolio_dialog.aboutToShow.connect(function() {
                portfolio_name_field.text = ""
              })
            }
          }
        }

        onAccepted: {
          if (portfolio_name_field.text.trim() !== "") {
            controller.addPortfolio(portfolio_name_field.text)
          }
        }
      }
    }

    // lower
    Rectangle {
      Layout.fillWidth: true
      Layout.fillHeight: true
      color: "#130e2b"
      border.color: "black"

      ListView {
        id: portfolioListView
        model: controller.portfolios
        anchors.fill: parent
        clip: true
        spacing: 10

        delegate: Rectangle {
          anchors.horizontalCenter: parent.horizontalCenter
          width: parent.width * 0.4
          height: 60
          radius: 5
          border.color: "white"

          RowLayout {
            anchors.fill: parent
            anchors.leftMargin: 10

            Column {
              Layout.fillWidth: true
              spacing: 3

              Text {
                text: modelData
                font.bold: true
                font.pointSize: 10
              }

              Text {
                text: "Value: "
                font.pointSize: 10
                color: "gray"
              }
            }

            RowLayout {
              Column {
                spacing: 3
                visible: controller.portfolios_number > 0

                Button {
                  x: 0
                  text: "Manage"
                  highlighted: true
                  onClicked: {
                    main_stack_view.push("portfolio.qml", {"portfolio_index": index})
                  }
                }
                Button {
                  x: 0
                  text: "Remove"
                  highlighted: true
                  onClicked: {
                    controller.removePortfolio(index)
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}
