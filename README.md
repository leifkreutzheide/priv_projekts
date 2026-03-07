# priv_projekts

the weather logger script does the following:
  1) gets weather data
  2) puts into excel doc
  
  one can then add a label to every data point. in this case it is an interger 1-10 whereas:
  1: singlet 
  .
  .
  10: singlet, long sleeve thermal, jumper, winter jacket, thermal bottoms, thick pants, and two pairs of socks.
  
  this is just a data collecting script with the intention of collecting data samples for ML. the code is machine generated but all comments are man made.

  how to change location: find coordinates at https://www.latlong.net/
  how to add more weather variables: browse available at https://open-meteo.com/en/docs, copy variable name and add it to WEATHER_VARIABLES, add matching readable label to VARIABLE_LABELS (must be same order)
  note: columns appear sequentially, henceforth no gaps appear if days are skipped
