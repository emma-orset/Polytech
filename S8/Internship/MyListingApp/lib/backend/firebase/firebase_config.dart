import 'package:firebase_core/firebase_core.dart';
import 'package:flutter/foundation.dart';

Future initFirebase() async {
  if (kIsWeb) {
    await Firebase.initializeApp(
        options: FirebaseOptions(
            apiKey: "AIzaSyCnAeDA11FSXnXMnLkfkFTL1gf1awbNr04",
            authDomain: "chibichanmylistingapp.firebaseapp.com",
            projectId: "chibichanmylistingapp",
            storageBucket: "chibichanmylistingapp.appspot.com",
            messagingSenderId: "156563058724",
            appId: "1:156563058724:web:838c2d3803377686e368b1"));
  } else {
    await Firebase.initializeApp();
  }
}
