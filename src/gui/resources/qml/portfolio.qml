import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
  property int portfolio_index
  id: root
  color: "#130e2b"

  ColumnLayout {
    anchors.fill: parent
    spacing: 0

    Button {
      text: "back"
      onClicked: {
        main_stack_view.pop()
      }
    }

    // upper
    Rectangle {
      Layout.fillWidth: true
      Layout.preferredHeight: parent.height * 0.25
      color: "#130e2b"
      //border.color: "black"

      Column {
        anchors.centerIn: parent
        spacing: 10

        Text {
          anchors.horizontalCenter: parent.horizontalCenter
          color: "white"
          font.pointSize: 20
          text: controller.portfolio_name
        }

        Text {
          color: "white"
          font.pointSize: 20
          text: " Total value: " + controller.portfolio_value
        }

        Button {
          anchors.horizontalCenter: parent.horizontalCenter
          text: "Add asset"
          onClicked: add_asset_dialog.open()
        }
      }

      Dialog {
        id: add_asset_dialog
        anchors.centerIn: parent
        modal: true
        standardButtons: Dialog.Ok | Dialog.Cancel
        height: 300

        contentItem: ColumnLayout {
          width: parent.width

          Label {
            text: "Name:"
            Layout.alignment: Qt.AlignLeft
          }

          TextField {
            id: asset_name_field
            Layout.fillWidth: true
            focus: true

            Component.onCompleted: {
              add_asset_dialog.aboutToShow.connect(function() {
                asset_name_field.text = ""
              })
            }
          }

          Label {
            text: "Ticker:"
            Layout.alignment: Qt.AlignLeft
          }

          TextField {
            id: asset_ticker_field
            Layout.fillWidth: true
            focus: true

            Component.onCompleted: {
              add_asset_dialog.aboutToShow.connect(function() {
                asset_ticker_field.text = ""
              })
            }
          }

          Label {
            text: "Type:"
            Layout.alignment: Qt.AlignLeft
          }

          ComboBox {
            id: asset_type_field
            Layout.fillWidth: true
            focus: true
            model: ["Crypto", "ETF", "Stock"]
          }

          Label {
            text: "Currency:"
            Layout.alignment: Qt.AlignLeft
          }

          ComboBox {
            id: asset_currency_field
            Layout.fillWidth: true
            focus: true
            model: ["PLN", "EUR", "USD"]
          }

        }

        onAccepted: {
          if (asset_name_field.text.trim() !== "") {
            if (asset_ticker_field.text.trim() !== "") {
              controller.addAsset(
                portfolio_index,
                asset_name_field.text,
                asset_ticker_field.text,
                asset_type_field.currentText,
                asset_currency_field.text)
            }
          }
        }
      }
    }

    // lower
    Rectangle {
      Layout.fillWidth: true
      Layout.fillHeight: true
      color: "#130e2b"
      //border.color: "black"

      ListView {
        id: portfolioListView
        model: controller.assets
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
                text: "Value: " + controller.asset_value
                font.pointSize: 10
                color: "gray"
              }
            }

            RowLayout {
              Column {
                spacing: 3
                //visible: controller.portfolios_number > 0

                Button {
                  x: 0
                  text: "Manage"
                  highlighted: true
                  onClicked: {
                    controller.printE()
                    console.log("#", index)
                    controller.setCurrentAsset(index)
                    main_stack_view.push("asset.qml", {"portfolio_index": portfolio_index, "asset_index": index})
                  }
                }
                Button {
                  x: 0
                  text: "Remove"
                  highlighted: true
                  onClicked: {
                    controller.removeAsset(root.portfolio_index, index)
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
