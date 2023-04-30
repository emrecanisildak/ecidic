import QtQuick 2.15
import QtCharts 2.0
import QtQuick.Shapes 1.4


Item{
    id:root
    width:500
    height:550
    z:104

    ChartView {
        id:powerChart
        title: "Energy Consumption"
        anchors.fill: parent
        legend.visible: false
        antialiasing: true
        backgroundColor: "black"
        plotAreaColor: "black"

        Component.onCompleted: {
            console.log("Power consumption controller component loaded..")
            console.log(powerChart.plotArea) // todo cpp
            power_cc_mapper.series = series10
        }

        // X AXIS
        ValueAxis {
            id: xAxis
            min:power_cc.minChartTDT
            max:0
            tickCount: 4
            color:"red"
            gridLineColor: "red"
            labelsColor: "gray"
        }

        // Y AXIS
        ValueAxis {
            id: yAxis
            min: power_cc.minChartPowerConsumption
            max: power_cc.maxChartPowerConsumption
            tickCount:5
            color:"red"
            gridLineColor: "red"
            labelsColor: "gray"
        }

        // Data Model
        LineSeries {
            id:series10
            axisX: xAxis
            axisY: yAxis
            color:"gray"
        }

        // AVG Line
        Shape {
            id:avgConsumptionLine
            width: powerChart.width
            height: powerChart.height
            z:powerChart.z+1
            anchors.centerIn: parent
            ShapePath {
                id:avgShapePath
                strokeWidth: 6
                strokeColor: "gray"
                strokeStyle: ShapePath.DashLine
                dashPattern: [ 1, 4 ]
                startX: powerChart.plotArea.x +5 ;
                startY: power_cc.yPosAVGLine
                PathLine {
                    id:avgConsumptionPathLine
                    x: powerChart.plotArea.x + powerChart.plotArea.width+7;
                    y:power_cc.yPosAVGLine
                }
            }

           Text {
                y: avgConsumptionPathLine.y
                x: avgConsumptionPathLine.x
                width:50
                height:20
                z:powerChart.z+1
                color:"white"
                text: "AVG"
            }
     }


    }
}
