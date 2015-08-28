using UnityEngine;
using System.Collections;

public class load_menu : MonoBehaviour {

	public int levelID;
	private bool mouseOver;

	private TextMesh textm;

	// Use this for initialization
	void Start () {
		textm = GetComponent<TextMesh> ();
	}
	
	// Update is called once per frame
	void Update () {
		if (mouseOver) {
			if (Input.GetMouseButtonDown(0)){
				Application.LoadLevel(levelID);
			}
		}
	}
	
	void OnMouseEnter(){
		if (textm != null) {
			textm.color = new Color (0, 255, 0);
		}
		mouseOver = true;
	}
	
	void OnMouseExit(){
		if (textm != null) {
			textm.color = new Color (255, 255, 255);
		}
		mouseOver = false;
	}
	
}
