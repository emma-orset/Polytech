// Automatic FlutterFlow imports
import '/backend/backend.dart';
import '/flutter_flow/flutter_flow_theme.dart';
import '/flutter_flow/flutter_flow_util.dart';
import 'index.dart'; // Imports other custom actions
import '/flutter_flow/custom_functions.dart'; // Imports custom functions
import 'package:flutter/material.dart';
// Begin custom action code
// DO NOT REMOVE OR MODIFY THE CODE ABOVE!

// Set your action name, define your arguments and return parameter,
// and then add the boilerplate code using the button on the right!

Future<List<String>?> returnAllTypes(String currentUserId) async {
  List<String> typesList = [];

  // Récupérer la référence à la collection "users" de Firestore
  CollectionReference usersRef = FirebaseFirestore.instance.collection('users');

  // Récupérer la référence à la sous-collection "medias" de l'utilisateur connecté
  CollectionReference mediasRef =
      usersRef.doc(currentUserId).collection('medias');

  // Récupérer tous les documents de la sous-collection "medias"
  QuerySnapshot mediaDocs = await mediasRef.get();

  // Parcourir tous les documents et extraire les types
  mediaDocs.docs.forEach((mediaDoc) {
    String type = mediaDoc.get('type').toString().toLowerCase();

    // Ajouter le type à la liste s'il n'existe pas déjà
    if (!typesList.contains(type)) {
      typesList.add(type);
    }
  });

  // Trier la liste des types par ordre alphabétique
  typesList.sort();

  return typesList;
}
