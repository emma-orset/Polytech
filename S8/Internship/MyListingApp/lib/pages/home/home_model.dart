import '/auth/firebase_auth/auth_util.dart';
import '/backend/backend.dart';
import '/components/no_match_search/no_match_search_widget.dart';
import '/flutter_flow/flutter_flow_icon_button.dart';
import '/flutter_flow/flutter_flow_theme.dart';
import '/flutter_flow/flutter_flow_toggle_icon.dart';
import '/flutter_flow/flutter_flow_util.dart';
import '/flutter_flow/flutter_flow_widgets.dart';
import '/modals/last_seen_b_s/last_seen_b_s_widget.dart';
import '/popups/log_out_anonymous_popup/log_out_anonymous_popup_widget.dart';
import '/custom_code/actions/index.dart' as actions;
import '/flutter_flow/custom_functions.dart' as functions;
import 'package:easy_debounce/easy_debounce.dart';
import 'package:flutter/material.dart';
import 'package:flutter/scheduler.dart';
import 'package:flutter_spinkit/flutter_spinkit.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:provider/provider.dart';

class HomeModel extends FlutterFlowModel {
  ///  Local state fields for this page.

  bool boolSearch = false;

  bool boolInProgressButton = false;

  bool boolToStartButton = false;

  bool boolFinishedButton = false;

  bool boolWatchButton = false;

  bool boolReadButton = false;

  bool boolFavoriteButton = false;

  List<String> listTypes = [];
  void addToListTypes(String item) => listTypes.add(item);
  void removeFromListTypes(String item) => listTypes.remove(item);
  void removeAtIndexFromListTypes(int index) => listTypes.removeAt(index);
  void updateListTypesAtIndex(int index, Function(String) updateFn) =>
      listTypes[index] = updateFn(listTypes[index]);

  List<String> clickedTags = [];
  void addToClickedTags(String item) => clickedTags.add(item);
  void removeFromClickedTags(String item) => clickedTags.remove(item);
  void removeAtIndexFromClickedTags(int index) => clickedTags.removeAt(index);
  void updateClickedTagsAtIndex(int index, Function(String) updateFn) =>
      clickedTags[index] = updateFn(clickedTags[index]);

  List<String> clickedTypes = [];
  void addToClickedTypes(String item) => clickedTypes.add(item);
  void removeFromClickedTypes(String item) => clickedTypes.remove(item);
  void removeAtIndexFromClickedTypes(int index) => clickedTypes.removeAt(index);
  void updateClickedTypesAtIndex(int index, Function(String) updateFn) =>
      clickedTypes[index] = updateFn(clickedTypes[index]);

  ///  State fields for stateful widgets in this page.

  final unfocusNode = FocusNode();
  // Stores action output result for [Custom Action - returnAllTags] action in Home widget.
  List<String>? allTagsFromUser;
  // Stores action output result for [Custom Action - returnAllTypes] action in Home widget.
  List<String>? allTypesFromUser;
  // State field(s) for SearchField widget.
  TextEditingController? searchFieldController;
  String? Function(BuildContext, String?)? searchFieldControllerValidator;
  // Model for NoMatchSearch component.
  late NoMatchSearchModel noMatchSearchModel;

  /// Initialization and disposal methods.

  void initState(BuildContext context) {
    noMatchSearchModel = createModel(context, () => NoMatchSearchModel());
  }

  void dispose() {
    unfocusNode.dispose();
    searchFieldController?.dispose();
    noMatchSearchModel.dispose();
  }

  /// Action blocks are added here.

  /// Additional helper methods are added here.
}
