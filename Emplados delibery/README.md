# 🚚 Sistema de Gestión de Repartidores (Delivery)

![C++](https://img.shields.io/badge/language-C%2B%2B-blue.svg)
![Status](https://img.shields.io/badge/status-completed-green.svg)
![Type](https://img.shields.io/badge/project-academic-lightgrey.svg)

Sistema de gestión de repartidores desarrollado en C++, que permite analizar información de entregas, reclamos y rendimiento general de una empresa de delivery.

---

## 📌 Descripción

El sistema trabaja con un conjunto de 50 repartidores y permite realizar distintos análisis sobre sus datos, como rendimiento, promedios y distribución de entregas.

---

## 🧱 Modelo de datos

Se utilizan estructuras (`struct`) anidadas:

### DatosRepartidor
- Nombre y apellido
- DNI

### Repartidor
- Departamento
- Zona
- Año de ingreso
- Cantidad de reclamos
- Entregas mensuales (12 meses)
- Datos personales (`DatosRepartidor`)

---

## ⚙️ Funcionalidades

### 📊 Repartidores sin reclamos
Muestra todos los repartidores que no registran reclamos.

### 🏆 Mayor cantidad de entregas (Nov + Dic)
Identifica al/los repartidores con mejor desempeño en los últimos dos meses del año.

### 📈 Promedio de entregas en abril
Calcula el promedio de entregas del mes de abril según la zona ingresada.

### 📦 Porcentaje de entregas por trimestre
Calcula la distribución porcentual de entregas por trimestre en una zona específica.

---

## 🛠️ Tecnologías utilizadas

- Lenguaje: **C++**
- Paradigma: **Programación estructurada**
- Conceptos:
  - `struct`
  - arreglos
  - funciones
  - control de flujo

---

## 🚀 Ejecución

```bash
g++ main.cpp -o delivery
./delivery
