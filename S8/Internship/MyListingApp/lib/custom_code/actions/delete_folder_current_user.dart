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

import 'package:firebase_storage/firebase_storage.dart';

Future<void> deleteFolderCurrentUser(String userId) async {
  Reference userFolderRef =
      FirebaseStorage.instance.ref().child('users/$userId');

  Future<void> deleteFolderContents(Reference folder) async {
    final ListResult result = await folder.listAll();

    for (final item in result.items) {
      await item.delete();
    }

    for (final prefix in result.prefixes) {
      await deleteFolderContents(prefix);
    }
  }

  try {
    final listResult = await userFolderRef.listAll();

    if (listResult.items.isNotEmpty || listResult.prefixes.isNotEmpty) {
      await deleteFolderContents(userFolderRef);
    }
  } catch (e) {
    print('Error folder : $e');
  }
}
